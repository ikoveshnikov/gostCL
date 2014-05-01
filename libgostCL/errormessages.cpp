#include "errormessages.h"

std::string GetErrorMessage(int errorCode)
{
    switch (errorCode) {
    case 0:
        return std::string ("Successfully done. No error found");
        break;

    case 1:
        return std::string ("Cannot set user defined SBoxes: format is wrong");
        break;

    case 2:
        return std::string ("Encryption key is not set");
        break;

    default:
        return std::string ("Unknown error");
        break;
    }
}
