#include "gostclcrypter.h"
#include <iostream>
#include <vector>
#include <string>

void PrintHelp (const char * programName)
{
    std::cout <<
    "NAME"
    "\n\tgostCrypter - encryption tool implemented GOST 28147-89 using OpenCL boost"
    "\n"
    "\nSYNOPSIS"
    "\n\t" << programName << "[ -e | -d ] [ STRING | SOURCE DEST ]"
    "\n\t[-t THREADS -s SIZE] [-m MODE] [OPTION]..."
    "\n"
    "\nDESCRIPTION"
    "\n\tEncrypt file or string using GOST 28147-89."
    "\n\tCan encrypt/decrypt STRING ether SOURCE file. S-Boxes could"
    "\n\tbe specifized by user."
    "\n"
    "\n\t-e"
    "\n\t\tEncrypt file or string"
    "\n"
    "\n\t-d"
    "\n\t\tDecrypt file or string"
    "\n"
    "\n\t--help"
    "\n\t\tdisplay this help and exit"
    "\n"
    "\n\t-m, --mode-of-operation"
    "\n\t\tSet mode of operation for encryption algorythm. ECB, CBC,"
    "\n\t\tOFB, CFB modes are possinle values. If not specified used"
    "\n\t\tECB as default"
    "\n"
    "\n\t-b, --custom-s-boxes"
    "\n\t\tSet custom S-Boxes for encryption algorythm. Could be stored"
    "\n\t\tin file either could be entered by user"
    "\n"
    "\n\t-t, --threads-count"
    "\n\t\tSet number of threads, encrypted separetely at the same time,"
    "\n\t\tcould decrease encryption time depending on mode of operation"
    "\n"
    "\n\t-s, --threads-size"
    "\n\t\tSet thread size in megabytes"
    "\n"
    << std::endl;
}


int main(int argc, char *argv[])
{
    if ((argc > 11) || (argc <= 2))
    {
        PrintHelp(argv[0]);
        return 1;
    }

    std::string input;
    std::string output;

    int encrypt = -1;
    std::string mode;
    bool customSBoxes = false;

    long threads = -1;
    long threadSize = -1;

    for (int i=1; i<argc; i++)
    {
        if (std::string(argv[i]) == "--help")
        {
            PrintHelp(argv[0]);
            return 1;
        }
    }

    std::vector <bool> usedArgs;
    usedArgs.reserve(argc);
    usedArgs.push_back(true);
    for (int i=1; i<argc; i++)
    {
        usedArgs.push_back(false);
    }

    //catch custom sboxes option
    for (int i=1; i<argc; i++)
    {
        if ((std::string(argv[i]) == "--custom-s-boxes") ||
            (std::string(argv[i]) == "-b")               )
        {
            if (customSBoxes)
            {
                PrintHelp(argv[0]);
                return 1;
            } // for the repeated action used

            customSBoxes = true;
            usedArgs.at(i) = true;
        }
    }

    //catch either encrypt or decrypt
    for (int i=1; i<argc; i++)
    {
        if (usedArgs.at(i))
        {
            continue;
        }

        if ((std::string(argv[i]) == "-e") ||
            (std::string(argv[i]) == "-d") )
        {
            if (-1 != encrypt)
            {
                PrintHelp(argv[0]);
                return 1;
            } // for the repeated action used

            if (std::string(argv[i]) == "-e")
            {
                encrypt = 1;
            }
            else
            {
                encrypt = 0;
            }
            usedArgs.at(i) = true;
        }
    }

    //catch mode of operation
    for (int i=1; i<argc; i++)
    {
        if (usedArgs.at(i))
        {
            continue;
        }

        if ((std::string(argv[i]) == "--mode-of-operation") ||
            (std::string(argv[i]) == "-m")                  )
        {
            if (0 !=mode.size())
            {
                PrintHelp(argv[0]);
                return 1;
            } // for the repeated action used

            if ((i+1 < argc)                &&
                (argv[i+1][0] != '-')       &&
                (false == usedArgs.at(i+1)) )
            {
                mode = argv[i+1];
                usedArgs.at(i) = true;
                usedArgs.at(i+1) = true;
            }
            else
            {
                PrintHelp(argv[0]);
                return 1;
            }
        }
    }


    //catch threds count
    for (int i=1; i<argc; i++)
    {
        if (usedArgs.at(i))
        {
            continue;
        }

        if ((std::string(argv[i]) == "--threads-count") ||
            (std::string(argv[i]) == "-t")              )
        {
            if (-1 !=threads)
            {
                PrintHelp(argv[0]);
                return 1;
            } // for the repeated action used

            if ((i+1 < argc)                &&
                (argv[i+1][0] != '-')       &&
                (false == usedArgs.at(i+1)) )
            {
                char * pEnd;
                threads = strtol(argv[i+1], &pEnd, 10);
                if (0L == threads)
                {
                    PrintHelp(argv[0]);
                    return 1;
                }
                usedArgs.at(i) = true;
                usedArgs.at(i+1) = true;
            }
            else
            {
                PrintHelp(argv[0]);
                return 1;
            }
        }
    }

    //catch thread size
    for (int i=1; i<argc; i++)
    {
        if (usedArgs.at(i))
        {
            continue;
        }

        if ((std::string(argv[i]) == "--thread-size") ||
            (std::string(argv[i]) == "-s")            )
        {
            if (-1 !=threadSize)
            {
                PrintHelp(argv[0]);
                return 1;
            } // for the repeated action used

            if ((i+1 < argc)                &&
                (argv[i+1][0] != '-')       &&
                (false == usedArgs.at(i+1)) )
            {
                char * pEnd;
                threadSize = strtol(argv[i+1], &pEnd, 10);
                if (0L == threadSize)
                {
                    PrintHelp(argv[0]);
                    return 1;
                }
                usedArgs.at(i) = true;
                usedArgs.at(i+1) = true;
            }
            else
            {
                PrintHelp(argv[0]);
                return 1;
            }
        }
    }

    //at this moment only input string or input/output file
    size_t inputIndex = 0;
    size_t outputIndex = 0;

    for (size_t i=0; i<usedArgs.size(); i++)
    {
        if (false == usedArgs.at(i))
        {
            if (0 == inputIndex)
            {
                inputIndex = i;
            }
            else if (0 == outputIndex)
            {
                outputIndex = i;
            }
            else
            {
                PrintHelp(argv[0]);
                return 1;
            }
        }
    }

    bool fileEncoding = false;

    if (0 == inputIndex)
    {
        PrintHelp(argv[0]);
        return 1;
    }
    else
    {
        input = argv[inputIndex];
        if (0 != outputIndex)
        {
            output = argv[outputIndex];
            fileEncoding = true;
        }
    }

    //encrypt or decrypt must be set
    if (-1 == encrypt)
    {
        PrintHelp(argv[0]);
        return 1;
    }
    //thread size must be set if threads count is set. and vice versa
    if (((threads  > 0) && (threadSize <= 0)) ||
        ((threads <= 0) && (threadSize  > 0)) )
    {
        PrintHelp(argv[0]);
        return 1;
    }

    GostCLCrypter gcrypter;

    if (!gcrypter.Init())
    {
        std::cout << "Couldn't load GostCL library!" << std::endl;
        return 1;
    }

    if (1 == encrypt)
    {
        gcrypter.GrabEncryptionKey(GostCLCrypter::Encrypt);

        if (customSBoxes)
        {
            gcrypter.SetSBoxes();
        }

        if (false == fileEncoding)
        {
            gcrypter.EncyptString(input, output, mode);

            std::cout << "\n" << output <<std::endl;
        }
        else
        {
            gcrypter.EncyptFile(input, output, mode, threads, threadSize);

            std::cout << "\nDone.\n" << output <<std::endl;
        }


    }
    else
    {
        if (customSBoxes)
        {
            gcrypter.SetSBoxes();
        }

        if (false == fileEncoding)
        {
            gcrypter.DecryptString(input, output, mode);

            std::cout << "\n" << output <<std::endl;
        }
        else
        {
            gcrypter.DecryptFile(input, output, mode, threads, threadSize);

            std::cout << "\nDone.\n" << output <<std::endl;
        }
    }


    return 0;
}
