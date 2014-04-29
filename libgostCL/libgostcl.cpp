#include "libgostcl.h"
#include "settingsholder.h"
#include "errormessages.h"


LibGostCL::LibGostCL()
    : errorCode (0)
{
}

bool LibGostCL::SetSBoxes(const std::vector<std::vector<int> > &boxes)
{
    SettingsHolder::Instance().SetSBoxes(boxes);

    errorCode = SettingsHolder::Instance().GetErrorCode();
    if (0 != errorCode)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool LibGostCL::SetEncryptionKey(const std::string &key)
{
    errorCode = 0;
    return SettingsHolder::Instance().SetKey(key);
}

std::string LibGostCL::GetErrorString()
{
    return GetErrorMessage(errorCode);
}
