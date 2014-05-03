#ifndef GOSTCLCRYPTER_H
#define GOSTCLCRYPTER_H

#include <string>

class LibGostCL;

class GostCLCrypter
{
public:
    GostCLCrypter();
    ~GostCLCrypter();

    //loads library
    bool Init ();

    bool GrabEncryptionKey (bool encryptionMode);

    bool EncyptFile (std::string fileNameIn,
                     std::string fileNameOut,
                     int treads = 1,
                     int threadSize = -1);

    bool DecyptFile (std::string fileNameIn,
                     std::string fileNameOut,
                     int treads = 1,
                     int threadSize = -1);


private:
    std::string ReadStringConsole (bool confirm);

    std::string encryptionKey;

    LibGostCL * clCrypter;
};

#endif // GOSTCLCRYPTER_H
