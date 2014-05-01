#include "libgostcl_c.h"
#include "settingsholder.h"
#include "errormessages.h"
//#include "cstring"

int SetSBoxes(const char * const standartID)
{
    if (standartID == std::string("id_GostR3411_94_TestParamSet"))
    {
        SettingsHolder::Instance().SetStandartSBoxes(
                    SettingsHolder::id_GostR3411_94_TestParamSet);
        return 0;
    }
    if (standartID == std::string("id_Gost28147_89_CryptoPro_A_ParamSet"))
    {
        SettingsHolder::Instance().SetStandartSBoxes(
                    SettingsHolder::id_Gost28147_89_CryptoPro_A_ParamSet);
        return 0;
    }
    if (standartID == std::string("id_Gost28147_89_CryptoPro_B_ParamSet"))
    {
        SettingsHolder::Instance().SetStandartSBoxes(
                    SettingsHolder::id_Gost28147_89_CryptoPro_B_ParamSet);
        return 0;
    }
    if (standartID == std::string("id_Gost28147_89_CryptoPro_C_ParamSet"))
    {
        SettingsHolder::Instance().SetStandartSBoxes(
                    SettingsHolder::id_Gost28147_89_CryptoPro_C_ParamSet);
        return 0;
    }
    if (standartID == std::string("id_Gost28147_89_CryptoPro_D_ParamSet"))
    {
        SettingsHolder::Instance().SetStandartSBoxes(
                    SettingsHolder::id_Gost28147_89_CryptoPro_D_ParamSet);
        return 0;
    }
    if (standartID == std::string("id_tc26_gost_28147_param_A"))
    {
        SettingsHolder::Instance().SetStandartSBoxes(
                    SettingsHolder::id_tc26_gost_28147_param_A);
        return 0;
    }
    return 1;
}


void SetEncryptionKey(const char * const key)
{
    std::string keyStr (key);

    SettingsHolder::Instance().SetKey(keyStr);
}
