#ifndef GOSTCLCRYPTER_H
#define GOSTCLCRYPTER_H

#include <string>

class LibGostCL;

class GostCLCrypter
{
public:
    GostCLCrypter();
    ~GostCLCrypter();

    enum Operation
    {
        Encrypt,
        Decrypt
    };

    //loads library
    bool Init ();

    bool GrabEncryptionKey (const Operation encryptionMode);
    bool SetSBoxes ();

    bool EncyptFile (const std::string fileNameIn,
                     const std::string fileNameOut,
                     const std::string modeOfOperation,
                     int threads = 1,
                     int threadSize = -1);

    bool DecryptFile (const std::string fileNameIn,
                     const std::string fileNameOut,
                     const std::string modeOfOperation,
                     int threads = 1,
                     int threadSize = -1);

    bool EncyptString (const std::string stringIn,
                       std::string stringOut,
                       const std::string modeOfOperation);

    bool DecryptString (const std::string stringIn,
                       std::string stringOut,
                       const std::string modeOfOperation);


private:
    std::string ReadStringConsole (bool confirm);

    std::string encryptionKey;

    LibGostCL * clCrypter;
};

#endif // GOSTCLCRYPTER_H
