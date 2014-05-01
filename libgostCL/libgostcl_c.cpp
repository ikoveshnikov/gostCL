#include "libgostcl_c.h"
#include "settingsholder.h"
#include "errormessages.h"
#include "crypter.h"
#include "cstring"

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


int Encrypt (const char * const data,
             unsigned long datasize,
             char * result,
             int mode,
             int threads,
             int threadSize,
             char * errorStr)
{
    LibGostCL::ModeOfOperation operationMode;
    switch (mode)
    {
    case 0:
        operationMode = LibGostCL::ECB;
        break;
    case 1:
        operationMode = LibGostCL::CBC;
        break;
    case 2:
        operationMode = LibGostCL::OFB;
        break;
    case 3:
        operationMode = LibGostCL::CFB;
        break;
    default:
        strcpy(errorStr, GetErrorMessage(4).c_str());
        return 1;
        break;
    }

    std::vector <unsigned char> input;
    std::vector <unsigned char> output;

    input.resize(datasize);
    output.resize(datasize);

    for (unsigned long i=0; i<datasize; i++)
    {
        input.push_back( data[i] );
    }

    Crypter gCrypter;

    gCrypter.SetModeOfOperation(operationMode);
    gCrypter.SetThreadsCount(threads);
    gCrypter.SetThreadsSize(threadSize);

    bool success = gCrypter.Encrypt(&input, &output);

    for (size_t i=0; i<output.size(); i++)
    {
        result[i] = output.at(i);
    }

    strcpy(errorStr, GetErrorMessage(gCrypter.GetErrorCode()).c_str());

    return ((success == true) ? 0 : 1) ;
}

int Decrypt (const char * const data,
             unsigned long datasize,
             char *result,
             int mode,
             int threads,
             int threadSize,
             char * errorStr)
{
    LibGostCL::ModeOfOperation operationMode;
    switch (mode)
    {
    case 0:
        operationMode = LibGostCL::ECB;
        break;
    case 1:
        operationMode = LibGostCL::CBC;
        break;
    case 2:
        operationMode = LibGostCL::OFB;
        break;
    case 3:
        operationMode = LibGostCL::CFB;
        break;
    default:
        strcpy(errorStr, GetErrorMessage(4).c_str());
        return 1;
        break;
    }

    std::vector <unsigned char> input;
    std::vector <unsigned char> output;

    input.resize(datasize);
    output.resize(datasize);

    for (unsigned long i=0; i<datasize; i++)
    {
        input.push_back( data[i] );
    }

    Crypter gCrypter;

    gCrypter.SetModeOfOperation(operationMode);
    gCrypter.SetThreadsCount(threads);
    gCrypter.SetThreadsSize(threadSize);

    bool success = gCrypter.Decrypt(&input, &output);

    for (size_t i=0; i<output.size(); i++)
    {
        result[i] = output.at(i);
    }

    strcpy(errorStr, GetErrorMessage(gCrypter.GetErrorCode()).c_str());

    return ((success == true) ? 0 : 1) ;
}
