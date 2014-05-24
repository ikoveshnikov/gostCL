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

    const std::vector <std::vector <int> > sboxes =
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

    const std::vector <std::vector <int> > sboxes =
            SettingsHolder::Instance().GetSBoxes();

    errorCode = -1;
    return false;
}

// files operations
bool Crypter::EncryptFile (const std::string  inputFile,
                           const std::string outputFile)
{
    if (!SetCryptKey())
    {
        return false;
    }

    const std::vector <std::vector <int> > sboxes =
            SettingsHolder::Instance().GetSBoxes();

    errorCode = -1;
    return false;
}

bool Crypter::DecryptFile (const std::string  inputFile,
                           const std::string outputFile)
{
    if (operationMode != LibGostCL::CFB)
    {
        errorCode = -1;
        return false;
    }

    if (!SetCryptKey())
    {
        return false;
    }

    const std::vector <std::vector <int> > sboxes =
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
                inFile.size() * sizeof(int));
        cl::Buffer outBuf = cl::Buffer(context, CL_MEM_WRITE_ONLY,
                outFile.size() * sizeof(int));
        cl::Buffer keyBuf = cl::Buffer(context, CL_MEM_WRITE_ONLY,
                encryptionKey.size() * sizeof(int));

        // Copy the input data to the input buffers using the
        // command queue for the first device
        queue.enqueueWriteBuffer(inBuf, CL_TRUE, 0,
                                 inFile.size() * sizeof(int),
                                 &inFile[0]);
        queue.enqueueWriteBuffer(keyBuf, CL_TRUE, 0,
                                 encryptionKey.size() * sizeof(int),
                                 &encryptionKey[0]);

        // Read the program source
        std::ifstream sourceFile("gostdecrypt.cl");

        std::string sourceCode( std::istreambuf_iterator<char>(sourceFile),
            (std::istreambuf_iterator<char>()));
        cl::Program::Sources source(1, std::make_pair(sourceCode.c_str(),
            sourceCode.length()+1));

        // Make program from the source code
        cl::Program program = cl::Program(context, source);

        // Build the program for the devices
        program.build(devices);

        // Make kernel
        cl::Kernel vecadd_kernel(program, "decrypt");

        // Set the kernel arguments
        vecadd_kernel.setArg(0, inBuf);
        vecadd_kernel.setArg(1, outBuf);
        vecadd_kernel.setArg(2, keyBuf);

        // Execute the kernel
        cl::NDRange global(inFile.size()/2);
        cl::NDRange local(128);
        queue.enqueueNDRangeKernel(vecadd_kernel, cl::NullRange, global, local);

        // Copy the output data back to the host
        queue.enqueueReadBuffer(outBuf, CL_TRUE, 0, outFile.size() * sizeof(int), &outFile[0]);

        // Verify the result
        std::ofstream out(outputFile, std::ios::binary);

        for (i=0; i<inFile.size(); i++)
        {
            out.write(reinterpret_cast<char*>(&inFile[i]), sizeof(uint32_t));
        }

      }
      catch(cl::Error error)
      {
        std::cout << error.what() << "(" <<
          error.err() << ")" << std::endl;
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

    for (int i=0; i<8; i++)
    {
        encryptionKey.push_back(0);
    }

    size_t key_size = key.size();

    for (size_t i=0, j=0; i<8; i++,j+=4)
    {
        encryptionKey[i] = key.at(  j   % key_size) |
                           key.at((j+1) % key_size) << 8 |
                           key.at((j+2) % key_size) << 16|
                           key.at((j+3) % key_size) << 24;
    }

    return true;

}
