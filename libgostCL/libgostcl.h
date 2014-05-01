#ifndef LIBGOSTCL_H
#define LIBGOSTCL_H

#include "libgostcl_global.h"
#include <vector>
#include <list>
#include <string>


class LIBGOSTCLSHARED_EXPORT LibGostCL
{

public:
    enum ModeOfOperation
    {
        ECB = 0,
        CBC = 1,
        OFB = 2,
        CFB = 3
    };


    LibGostCL();
    ~LibGostCL();

    bool SetSBoxes (const std::vector <std::vector <int> > & boxes);

    bool SetEncryptionKey (const std::string & key);

    bool Encrypt (const std::list <unsigned char> * const data,
                  const std::list <unsigned char> * result,
                  ModeOfOperation mode = ECB,
                  int threads = 1,
                  int theadSize = -1); // in megabytes

    bool Decrypt (const std::list <unsigned char> * const data,
                  const std::list <unsigned char> * result,
                  ModeOfOperation mode = ECB,
                  int threads = 1,
                  int theadSize = -1);

    std::string GetErrorString ();

private:
    int errorCode;


}; // class LibGostCL


#endif // LIBGOSTCL_H
