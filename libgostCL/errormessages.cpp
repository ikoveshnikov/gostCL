#include "errormessages.h"

static std::string GetErrorMessage(int errorCode)
{
    switch (errorCode) {
    case 0:
        return std::string ("Successfully done. No error found");
        break;

    default:
        break;
    }
}
