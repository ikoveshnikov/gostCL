#ifndef CRYPTER_H
#define CRYPTER_H

#include "libgostcl.h"

class Crypter
{
public:
    Crypter();
    ~Crypter();

    void SetModeOfOperation (LibGostCL::ModeOfOperation mode = LibGostCL::ECB);

    void SetThreadsCount (int threads);

    void SetThreadsSize (int megabytes);

    // strings operations
    bool Encrypt (const std::string input,
                  std::string output);

    bool Decrypt (const std::string input,
                  std::string output);

    // files operations
    bool EncryptFile (const std::string  inputFile,
                      const std::string outputFile);

    bool DecryptFile (const std::string  inputFile,
                      const std::string outputFile);

    int GetErrorCode ();

private:
    LibGostCL::ModeOfOperation operationMode;

    int threadsCount;
    int threadsSize;
    int errorCode;
};

#endif // CRYPTER_H
