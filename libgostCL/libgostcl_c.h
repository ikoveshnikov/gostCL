#ifndef LIBGOSTCL_C_H
#define LIBGOSTCL_C_H

#include "libgostcl_global.h"

extern "c" {

bool LIBGOSTCLSHARED_EXPORT SetSBoxes (const int & sboxes[]);

bool LIBGOSTCLSHARED_EXPORT SetEncryptionKey (const char * const key);

bool LIBGOSTCLSHARED_EXPORT
    Encrypt (const char * const data,
              int mode = 0,
              int threads = 1,
              int theadSize = -1); // in megabytes

bool LIBGOSTCLSHARED_EXPORT
    Decrypt (const char * const data,
              int mode = 0,
              int threads = 1,
              int theadSize = -1);

bool LIBGOSTCLSHARED_EXPORT
    GetResult (const char * data) const;

char *  LIBGOSTCLSHARED_EXPORT GetErrorString () const;


}

#endif // LIBGOSTCL_C_H
