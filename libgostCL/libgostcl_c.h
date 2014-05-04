#ifndef LIBGOSTCL_C_H
#define LIBGOSTCL_C_H

#include "libgostcl_global.h"

#ifdef __cplusplus
extern "C" {
#endif

int LIBGOSTCLSHARED_EXPORT SetSBoxes (const char * const standartID);

void LIBGOSTCLSHARED_EXPORT SetEncryptionKey (const char * const key);


// strings operations
int LIBGOSTCLSHARED_EXPORT
    Encrypt (const char * data,
             char *result,
             int mode = 0,
             char * errorStr = 0);

int LIBGOSTCLSHARED_EXPORT
    Decrypt (const char * data,
             char * result,
             int mode = 0,
             char * errorStr = 0);

// files operations
int LIBGOSTCLSHARED_EXPORT
    EncryptFile (const char * inputFile,
                 const char * outputFile,
                 int mode = 0,
                 int threads = 1,
                 int threadSize = -1,
                 char * errorStr = 0); // in megabytes

int LIBGOSTCLSHARED_EXPORT
    DecryptFile (const char * inputFile,
                 const char * outputFile,
                 int mode = 0,
                 int threads = 1,
                 int threadSize = -1,
                 char * errorStr = 0);

#ifdef __cplusplus
}
#endif

#endif // LIBGOSTCL_C_H
