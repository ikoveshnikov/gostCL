#include "errormessages.h"

std::string GetErrorMessage(int errorCode)
{
    switch (errorCode) {
    case -1:
        return std::string ("Not implemented");
        break;

    case 0:
        return std::string ("Successfully done. No error found");
        break;

    case 1:
        return std::string ("Cannot set user defined SBoxes: format is wrong");
        break;

    case 2:
        return std::string ("Encryption key is not set");
        break;

    case 3:
        return std::string ("Such standart sboxes don't exist");
        break;

    case 4:
        return std::string ("Mode of operation is unknown");
        break;

    case 5:
        return std::string ("Unexpected null pointer got!");
        break;

    case 6:
        return std::string ("");
        break;

    default:
        return std::string ("Unknown error");
        break;
    }
}
