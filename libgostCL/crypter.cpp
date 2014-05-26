#define __CL_ENABLE_EXCEPTIONS

#include "crypter.h"
#include "settingsholder.h"
#include "fstream"
#include "iostream"
#include <CL/cl.hpp>




Crypter::Crypter()
    : operationMode (LibGostCL::ECB)
    , threadsCount (1)
    , threadsSize (-1)
    , errorCode (0)
{
}

Crypter::~Crypter()
{

}

void Crypter::SetModeOfOperation (LibGostCL::ModeOfOperation mode)
{
    operationMode = mode;
}

void Crypter::SetThreadsCount (int threads)
{
    threadsCount = threads;
}

void Crypter::SetThreadsSize (int megabytes)
{
    threadsSize = megabytes;
}

int Crypter::GetErrorCode ()
{
    return errorCode;
}


// strings operations
bool Crypter::Encrypt (const std::string input,
                       std::string output)
{
    if (!SetCryptKey())
    {
        return false;
    }

    const std::vector <std::vector <C_U8> > sboxes =
            SettingsHolder::Instance().GetSBoxes();

    errorCode = -1;
    return false;
}

bool Crypter::Decrypt (const std::string input,
                       std::string output)
{
    if (!SetCryptKey())
    {
        return false;
    }

    const std::vector <std::vector <C_U8> > sboxes =
            SettingsHolder::Instance().GetSBoxes();

    errorCode = -1;
    return false;
}

// files operations
bool Crypter::EncryptFile (const std::string  inputFile,
                           const std::string outputFile)
{
    if (operationMode != LibGostCL::ECB)
    {
        errorCode = -1;
        return false;
    }

    if (!SetCryptKey())
    {
        return false;
    }

    const std::vector <std::vector <C_U8> > sboxes =
            SettingsHolder::Instance().GetSBoxes();



    std::ifstream in(inputFile, std::ios::binary);
    std::vector<C_U32> inFile, outFile;

    inFile.reserve(10000);
    outFile.reserve(10000);

    size_t i = 0;
    while (!in.eof())
    {
        inFile.push_back(0);
        outFile.push_back(0);
        in.read(reinterpret_cast<char*>(&inFile[i]), sizeof(uint32_t));
        i++;
    }

    if (inFile.size() % 2 == 1)
    {
        inFile.push_back(0);
        outFile.push_back(0);
    }

    gost_ctx gostContext;

    ContextInit(gostContext, encryptionKey, sboxes);

    if (!RunOCL(gostContext, inFile, outFile, false))
    {
        return false;
    }

    // write the result
    std::ofstream out(outputFile, std::ios::binary);
    for (i=0; i<outFile.size()-1; i++)
    {
        out.write(reinterpret_cast<char*>(&outFile[i]), sizeof(uint32_t));
    }
    if (outFile.at( outFile.size()-1 ) != 0)
    {
        out.write(reinterpret_cast<char*>(&outFile[outFile.size()-1]), sizeof(uint32_t));
    }

    return true;
}

bool Crypter::DecryptFile (const std::string  inputFile,
                           const std::string outputFile)
{
    if (operationMode != LibGostCL::ECB)
    {
        errorCode = -1;
        return false;
    }

    if (!SetCryptKey())
    {
        return false;
    }

    const std::vector <std::vector <C_U8> > sboxes =
            SettingsHolder::Instance().GetSBoxes();



    std::ifstream in(inputFile, std::ios::binary);
    std::vector<C_U32> inFile, outFile;

    inFile.reserve(10000);
    outFile.reserve(10000);

    size_t i = 0;
    while (!in.eof())
    {
        inFile.push_back(0);
        outFile.push_back(0);
        in.read(reinterpret_cast<char*>(&inFile[i]), sizeof(uint32_t));
        i++;
    }

    if (inFile.size() % 2 == 1)
    {
        inFile.push_back(0);
        outFile.push_back(0);
    }

    gost_ctx gostContext;

    ContextInit(gostContext, encryptionKey, sboxes);

    if (!RunOCL(gostContext, inFile, outFile, true))
    {
        return false;
    }

    // write the result
    std::ofstream out(outputFile, std::ios::binary);
    for (i=0; i<outFile.size()-1; i++)
    {
        out.write(reinterpret_cast<char*>(&outFile[i]), sizeof(uint32_t));
    }
    if (outFile.at( outFile.size()-1 ) != 0)
    {
        out.write(reinterpret_cast<char*>(&outFile[outFile.size()-1]), sizeof(uint32_t));
    }

    return true;
}

bool Crypter::SetCryptKey()
{
    std::string key = SettingsHolder::Instance().GetKey();

    if (key.size() == 0)
    {
        errorCode = 2;
        return false;
    }

    encryptionKey.clear();

    if (encryptionKey.size() != 8)
    {
        encryptionKey.resize(8);
    }

#ifndef DEBUG_BUILD
    size_t key_size = key.size();

    for (size_t i=0, j=0; i<8; i++,j+=4)
    {
        encryptionKey[i] = key.at(  j   % key_size) |
                           key.at((j+1) % key_size) << 8 |
                           key.at((j+2) % key_size) << 16|
                           key.at((j+3) % key_size) << 24;
    }

#endif

    return true;
}


bool Crypter::ContextInit(gost_ctx &context,
                          const std::vector <C_U32> encryptionKey,
                          const std::vector <std::vector <C_U8> > sboxes)
{
    if (encryptionKey.size() != 8)
    {
        return false;
    }

    if (sboxes.size() != 8)
    {
        return false;
    }

    for (size_t i=0; i<sboxes.size(); i++)
    {
        if (sboxes.at(i).size() != 16)
        {
            return false;
        }
    }

    for (size_t i=0; i<8; i++)
    {
        context.k[i] = encryptionKey.at(i);
    }

    for (size_t i = 0; i < 256; i++)
    {
        context.k87[i] = (sboxes.at(7).at(i>>4) <<4  | sboxes.at(6).at(i &15))<<24;
        context.k65[i] = (sboxes.at(5).at(i>>4) <<4  | sboxes.at(4).at(i &15))<<16;
        context.k43[i] = (sboxes.at(3).at(i>>4) <<4  | sboxes.at(2).at(i &15))<<8;
        context.k21[i] =  sboxes.at(1).at(i>>4) <<4  | sboxes.at(0).at(i &15);
    }

    return true;
}


bool Crypter::RunOCL(gost_ctx &gostContext,
                     const std::vector<C_U32> &inFile,
                     std::vector<C_U32> &outFile,
                     bool isDecrypt)
{
    try {
        // Query for platforms
        std::vector<cl::Platform> platforms;
        cl::Platform::get(&platforms);

        // Get a list of devices on this platform
        std::vector<cl::Device> devices;
        platforms[0].getDevices(CL_DEVICE_TYPE_GPU, &devices);

        // Create a context for the devices
        cl::Context context(devices);

        // Create a command queue for the first device
        cl::CommandQueue queue = cl::CommandQueue(context, devices[0]);

        // Create the memory buffers
        cl::Buffer inBuf = cl::Buffer(context, CL_MEM_READ_ONLY,
                inFile.size() * sizeof(C_U32));
        cl::Buffer outBuf = cl::Buffer(context, CL_MEM_WRITE_ONLY,
                outFile.size() * sizeof(C_U32));
        cl::Buffer contextBuf = cl::Buffer(context, CL_MEM_WRITE_ONLY,
                sizeof(gostContext));

        // Copy the input data to the input buffers using the
        // command queue for the first device
        queue.enqueueWriteBuffer(inBuf, CL_TRUE, 0,
                                 inFile.size() * sizeof(C_U32),
                                 &inFile[0]);
        queue.enqueueWriteBuffer(contextBuf, CL_TRUE, 0,
                                 sizeof(gostContext),
                                 &gostContext);

        // Read the program source
        std::ifstream sourceFile("gostdecrypt.cl");

        std::string sourceCode( std::istreambuf_iterator<char>(sourceFile),
            (std::istreambuf_iterator<char>()));
        cl::Program::Sources source(1, std::make_pair(sourceCode.c_str(),
            sourceCode.length()+1));

        // Make program from the source code
        cl::Program program = cl::Program(context, source);

        // Build the program for the devices
        try
        {
            program.build(devices);
        }
        catch(cl::Error error)
        {
            if(error.err() == CL_BUILD_PROGRAM_FAILURE)
            {
                std::cout << "Build log:" << std::endl << program.getBuildInfo<CL_PROGRAM_BUILD_LOG>(devices[0]) << std::endl;
            }
            throw error;
        }

        std::string function;


        if (isDecrypt)
        {
            function.append("decrypt");
        }
        else
        {
            function.append("encrypt");
        }

        switch (operationMode)
        {
        case LibGostCL::ECB:
            break;
        case LibGostCL::CBC:
            function.append("_cbc");
            break;
        case LibGostCL::OFB:
            function.append("_ofb");
            break;
        case LibGostCL::CFB:
            function.append("_cfb");
            break;
        default:
            break;
        }

        // Make kernel
        cl::Kernel derypt_kernel(program, function.c_str());

        // Set the kernel arguments
        derypt_kernel.setArg(0, inBuf);
        derypt_kernel.setArg(1, outBuf);
        derypt_kernel.setArg(2, contextBuf);

        // Execute the kernel
//        int maxRange = 1024;
        int maxRange = 1024;
        cl::NDRange global(maxRange);
        cl::NDRange local(128);
//        cl::NDRange offset = cl::NullRange;

//        cl::Event event;
//        queue.enqueueNDRangeKernel(derypt_kernel, offset, global, local, NULL, &event);
//        event.wait();

        for (size_t lastProcessedData = 0; lastProcessedData < inFile.size(); lastProcessedData+= maxRange)
        {
            queue.enqueueNDRangeKernel(derypt_kernel, cl::NDRange(lastProcessedData), global, local, NULL, NULL);
            queue.flush();
        }
        queue.finish();



        // Copy the output data back to the host
        queue.enqueueReadBuffer(outBuf, CL_TRUE, 0, outFile.size() * sizeof(int), &outFile[0]);

      }
      catch(cl::Error error)
      {
        std::cout << error.what() << "(" <<
          error.err() << ")" << std::endl;

        errorCode = 100 + (-1 * error.err());

        return false;
      }
    return true;
}
