#include "gostclcrypter.h"
#include <iostream>
#include <fstream>
#include "../libgostCL/libgostcl.h"

GostCLCrypter::GostCLCrypter()
{
}

GostCLCrypter::~GostCLCrypter()
{

}

bool Init ()
{

}

bool GostCLCrypter::GrabEncryptionKey (bool encryptionMode)
{
    if (encryptionMode)
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
    else
    {
        encryptionKey = ReadStringConsole(false);
    }

    return true;
}

std::string GostCLCrypter::ReadStringConsole (bool confirm)
{
    if (true == confirm)
    {
        std::cout << "Enter password again: " << endl;
    }
    else
    {
        std::cout << "Enter encryption password: " << end;
    }

    std::string key;

    std::cin >> key;

    return key;
}

bool GostCLCrypter::EncyptFile (std::string fileNameIn,
                                std::string fileNameOut,
                                int treads,
                                int threadSize)
{

}

bool GostCLCrypter::DecyptFile (std::string fileNameIn,
                                std::string fileNameOut,
                                int treads,
                                int threadSize)
{

}
