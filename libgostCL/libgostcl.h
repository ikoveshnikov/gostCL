#ifndef LIBGOSTCL_H
#define LIBGOSTCL_H

#include "libgostcl_global.h"
#include <list>
#include <string>

namespace GostCL {


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

    bool SetSBoxes ();

    bool SetKey ();

    bool Encrypt (const std::list * const data,
                  ModeOfOperation mode = ECB,
                  int threads = 1,
                  int theadSize = -1); // in megabytes

    bool Decrypt (const std::list * const data,
                  ModeOfOperation mode = ECB,
                  int threads = 1,
                  int theadSize = -1);

    bool GetResult (std::list * data) const;

    std::string GetErrorString ();

private:
    bool errorHappen;
    int errorCode;


}; // class LibGostCL


} // namespace GostCL

#endif // LIBGOSTCL_H
