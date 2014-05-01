#include "crypter.h"
#include "settingsholder.h"

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

bool Crypter::Encrypt (const std::vector <unsigned char> * const data,
                       const std::vector <unsigned char> * result)
{
    std::string key = SettingsHolder::Instance().GetKey();

    const std::vector <std::vector <int> > sboxes =
            SettingsHolder::Instance().GetSBoxes();

    if (0 == key.size())
    {
        errorCode = 2;
        return false;
    }
    return true;
}

bool Crypter::Decrypt (const std::vector <unsigned char> * const data,
                       const std::vector <unsigned char> * result)
{
    std::string key = SettingsHolder::Instance().GetKey();

    const std::vector <std::vector <int> > sboxes =
            SettingsHolder::Instance().GetSBoxes();

    if (0 == key.size())
    {
        errorCode = 2;
        return false;
    }

    return true;
}


