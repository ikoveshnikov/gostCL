#ifndef CRYPTER_H
#define CRYPTER_H

#include "libgostcl.h"
#include "crypt_types.h"

struct gost_ctx //gost context for ocl implementation
{
    // encryption key
    C_U32 k[8];
    /* Constant s-boxes -- set up in kboxinit() */
    C_U32 k87[256],k65[256],k43[256],k21[256];
} ;

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

    bool SetCryptKey ();

private:
    LibGostCL::ModeOfOperation operationMode;

    int threadsCount;
    int threadsSize;
    int errorCode;
    std::vector <C_U32> encryptionKey;

    static bool ContextInit (gost_ctx &context,
                             const std::vector <C_U32> encryptionKey,
                             std::vector <std::vector <C_U8> > sboxes);

    bool RunOCL (gost_ctx &gostContext,
                 const std::vector<C_U32> &inFile,
                 std::vector<C_U32> &outFile,
                 bool isDecrypt);
};

#endif // CRYPTER_H
