#include "gostclcrypter.h"
#include <iostream>

void PrintHelp (const char * programName)
{
    std::cout <<
    "NAME"
    "\n\tgostCrypter - encryption tool implemented GOST 28147-89 using OpenCL boost"
    "\n"
    "\nSYNOPSIS"
    "\n\t" << programName << " [ STRING | SOURCE DEST ]"
    "\n\t[-t THREADS -s SIZE] [-m MODE] [OPTION]..."
    "\n"
    "\nDESCRIPTION"
    "\n\tEncrypt file or string using GOST 28147-89."
    "\n\tCan encrypt/decrypt STRING ether SOURCE file. S-Boxes could"
    "\n\tbe specifized by user."
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

    PrintHelp(argv[0]);

    return 0;
}
