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
    if (clCrypter != 0)
    {
        delete clCrypter;
    }
}

bool GostCLCrypter::Init ()
{
    clCrypter = new (std::nothrow) LibGostCL;

    if (clCrypter != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
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
        std::cout << "Enter password again: ";
    }
    else
    {
        std::cout << "Enter encryption password: ";
    }

    std::string key;

    std::cin >> key;

    return key;
}

bool GostCLCrypter::EncyptFile (const std::string fileNameIn,
                                const std::string fileNameOut,
                                const std::string modeOfOperation,
                                int threads,
                                int threadSize)
{
    if (0 == clCrypter)
    {
        return false;
    }

    GrabEncryptionKey(Encrypt);

    clCrypter->SetEncryptionKey(encryptionKey);

    clCrypter->Encrypt(fileNameIn, fileNameOut,
                       clCrypter->ParseModeOfOperation(modeOfOperation),
                       threads, threadSize);

    return true;
}

bool GostCLCrypter::DecryptFile (const std::string fileNameIn,
                                 const std::string fileNameOut,
                                 const std::string modeOfOperation,
                                 int threads,
                                 int threadSize)
{
    if (0 == clCrypter)
    {
        return false;
    }

    GrabEncryptionKey(Decrypt);

    clCrypter->SetEncryptionKey(encryptionKey);

    clCrypter->Decrypt(fileNameIn, fileNameOut,
                       clCrypter->ParseModeOfOperation(modeOfOperation),
                       threads, threadSize);

    return true;

}

bool GostCLCrypter::EncyptString (const std::string stringIn,
                                  std::string stringOut,
                                  const std::string modeOfOperation)
{
    if (0 == clCrypter)
    {
        return false;
    }

    return true;
}

bool GostCLCrypter::DecryptString (const std::string stringIn,
                                   std::string stringOut,
                                   const std::string modeOfOperation)
{
    if (0 == clCrypter)
    {
        return false;
    }
    return true;
}

bool GostCLCrypter::SetSBoxes ()
{
    return false;
}
