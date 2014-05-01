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

    bool Encrypt (const std::vector <unsigned char> * const data,
                  const std::vector <unsigned char> * result);

    bool Decrypt (const std::vector <unsigned char> * const data,
                  const std::vector <unsigned char> * result);

    int GetErrorCode ();

private:
    LibGostCL::ModeOfOperation operationMode;

    int threadsCount;
    int threadsSize;
    int errorCode;
};

#endif // CRYPTER_H
