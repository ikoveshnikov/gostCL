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
    if (!SetCryptKey())
    {
        return false;
    }

    const std::vector <std::vector <int> > sboxes =
            SettingsHolder::Instance().GetSBoxes();

    if (operationMode != LibGostCL::CFB)
    {
        errorCode = -1;
        return false;
    }

    std::ifstream in(inputFile, std::ios::binary);
    std::vector<C_U32> fileContents;
    fileContents.reserve(fileSize);
    fileContents.assign(std::istreambuf_iterator<char>(testFile),
                        std::istreambuf_iterator<char>());

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
                           key.at((j+1) % key_size) |
                           key.at((j+2) % key_size) |
                           key.at((j+3) % key_size);
    }

    return true;

}
