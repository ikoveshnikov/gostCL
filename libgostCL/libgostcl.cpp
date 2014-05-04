#include "libgostcl.h"
#include "settingsholder.h"
#include "errormessages.h"
#include "crypter.h"


LibGostCL::LibGostCL()
    : errorCode (0)
{
}

LibGostCL::~LibGostCL()
{

}

bool LibGostCL::SetSBoxes(const std::vector<std::vector<int> > &boxes)
{
    SettingsHolder::Instance().SetSBoxes(boxes);

    errorCode = SettingsHolder::Instance().GetErrorCode();
    if (0 != errorCode)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool LibGostCL::SetEncryptionKey(const std::string &key)
{
    errorCode = 0;
    return SettingsHolder::Instance().SetKey(key);
}

std::string LibGostCL::GetErrorString()
{
    return GetErrorMessage(errorCode);
}


// strings operations
bool LibGostCL::Encrypt (const std::string input,
                         std::string output,
                         ModeOfOperation mode)
{
    Crypter gCrypter;

    gCrypter.SetModeOfOperation(mode);

    bool success = gCrypter.Encrypt(input, output);

    errorCode = gCrypter.GetErrorCode();

    return success;
}

bool LibGostCL::Decrypt (const std::string input,
                         std::string output,
                         ModeOfOperation mode)
{
    Crypter gCrypter;

    gCrypter.SetModeOfOperation(mode);

    bool success = gCrypter.Decrypt(input, output);

    errorCode = gCrypter.GetErrorCode();

    return success;
}

// files operations
bool LibGostCL::Encrypt (const std::string  inputFile,
                         const std::string outputFile,
                         ModeOfOperation mode,
                         int threads,
                         int threadSize)
{
    Crypter gCrypter;

    gCrypter.SetModeOfOperation(mode);
    gCrypter.SetThreadsCount(threads);
    gCrypter.SetThreadsSize(threadSize);

    bool success = gCrypter.EncryptFile(inputFile, outputFile);

    errorCode = gCrypter.GetErrorCode();

    return success;
}

bool LibGostCL::Decrypt (const std::string  inputFile,
                         const std::string outputFile,
                         ModeOfOperation mode,
                         int threads,
                         int threadSize)
{
    Crypter gCrypter;

    gCrypter.SetModeOfOperation(mode);
    gCrypter.SetThreadsCount(threads);
    gCrypter.SetThreadsSize(threadSize);

    bool success = gCrypter.DecryptFile(inputFile, outputFile);

    errorCode = gCrypter.GetErrorCode();

    return success;;
}
