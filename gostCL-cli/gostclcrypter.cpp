#include "gostclcrypter.h"
#include <iostream>
#include <fstream>
#include "../libgostCL/libgostcl.h"

GostCLCrypter::GostCLCrypter()
    : clCrypter (0)
{
}

GostCLCrypter::~GostCLCrypter()
{

}

bool GostCLCrypter::Init ()
{
    return true;
}

bool GostCLCrypter::GrabEncryptionKey (const Operation encryptionMode)
{
    if (Encrypt == encryptionMode)
    {
        bool keyGot = false;

        while (true != keyGot)
        {
            std::string key = ReadStringConsole(false);
            std::string confirm = ReadStringConsole(true);

            if (key == confirm)
            {
                keyGot = true;
                encryptionKey = key;
            }
        }
    }
    else if (Decrypt == encryptionMode)
    {
        encryptionKey = ReadStringConsole(false);
    }

    return true;
}

std::string GostCLCrypter::ReadStringConsole (bool confirm)
{
    if (true == confirm)
    {
        std::cout << "Enter password again: " << std::endl;
    }
    else
    {
        std::cout << "Enter encryption password: " << std::endl;
    }

    std::string key;

    std::cin >> key;

    return key;
}

bool GostCLCrypter::EncyptFile (const std::string fileNameIn,
                                const std::string fileNameOut, const std::string modeOfOperation,
                                int treads,
                                int threadSize)
{
    if (0 == clCrypter)
    {
        return false;
    }


    return true;
}

bool GostCLCrypter::DecyptFile (const std::string fileNameIn,
                                const std::string fileNameOut, const std::string modeOfOperation,
                                int treads,
                                int threadSize)
{
    if (0 == clCrypter)
    {
        return false;
    }


    return true;

}

bool GostCLCrypter::EncyptString (const std::string stringIn,
                                  std::string stringOut, const std::string modeOfOperation)
{
    if (0 == clCrypter)
    {
        return false;
    }

    return true;
}

bool GostCLCrypter::DecyptString (const std::string stringIn,
                                  std::string stringOut, const std::string modeOfOperation)
{
    if (0 == clCrypter)
    {
        return false;
    }
    return true;
}

bool GostCLCrypter::SetSBoxes ()
{

}
