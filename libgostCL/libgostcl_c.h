#ifndef LIBGOSTCL_C_H
#define LIBGOSTCL_C_H

#include "libgostcl_global.h"

extern "C" {

int LIBGOSTCLSHARED_EXPORT SetSBoxes (const char * const standartID);

void LIBGOSTCLSHARED_EXPORT SetEncryptionKey (const char * const key);

int LIBGOSTCLSHARED_EXPORT
    Encrypt (const char * const data,
              int mode = 0,
              int threads = 1,
              int theadSize = -1,
              char * errorStr = 0); // in megabytes

int LIBGOSTCLSHARED_EXPORT
    Decrypt (const char * const data,
              int mode = 0,
              int threads = 1,
              int theadSize = -1,
              char * errorStr = 0);

int LIBGOSTCLSHARED_EXPORT
    GetResult (const char * data);

}

#endif // LIBGOSTCL_C_H
