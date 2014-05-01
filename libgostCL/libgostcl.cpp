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

bool LibGostCL::Encrypt (const std::list <unsigned char> * const data,
                         const std::list <unsigned char> * result,
                         ModeOfOperation mode = ECB,
                         int threads = 1,
                         int threadSize = -1)
{
    Crypter gCrypter;

    gCrypter.SetModeOfOperation(mode);
    gCrypter.SetThreadsCount(threads);
    gCrypter.SetThreadsSize(threadSize);

    bool success = gCrypter.Encrypt(data, result);

    errorCode = gCrypter.GetErrorCode();

    return success;
}

bool LibGostCL::Decrypt (const std::list <unsigned char> * const data,
                         const std::list <unsigned char> * result,
                         ModeOfOperation mode = ECB,
                         int threads = 1,
                         int threadSize = -1)
{
    Crypter gCrypter;

    gCrypter.SetModeOfOperation(mode);
    gCrypter.SetThreadsCount(threads);
    gCrypter.SetThreadsSize(threadSize);

    bool success = gCrypter.Decrypt(data, result);

    errorCode = gCrypter.GetErrorCode();

    return success;
}
