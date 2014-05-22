#ifndef LIBGOSTCL_H
#define LIBGOSTCL_H

#include "libgostcl_global.h"
#include <vector>
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

    static ModeOfOperation ParseModeOfOperation (const std::string mode);

    // strings operations
    bool Encrypt (const std::string input,
                  std::string output,
                  ModeOfOperation mode = ECB);

    bool Decrypt (const std::string input,
                  std::string output,
                  ModeOfOperation mode = ECB);

    // files operations
    bool Encrypt (const std::string  inputFile,
                  const std::string outputFile,
                  ModeOfOperation mode = ECB,
                  int threads = 1,
                  int threadSize = -1); // in megabytes

    bool Decrypt (const std::string  inputFile,
                  const std::string outputFile,
                  ModeOfOperation mode = ECB,
                  int threads = 1,
                  int threadSize = -1);

    std::string GetErrorString ();

private:
    int errorCode;


}; // class LibGostCL


#endif // LIBGOSTCL_H
