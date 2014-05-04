#include "libgostcl_c.h"
#include "settingsholder.h"
#include "errormessages.h"
#include "crypter.h"
#include "cstring"

//------------------------------------------------------------------------------
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

//------------------------------------------------------------------------------
void SetEncryptionKey(const char * const key)
{
    std::string keyStr (key);

    SettingsHolder::Instance().SetKey(keyStr);
}

//------------------------------------------------------------------------------
// strings operations
//------------------------------------------------------------------------------
int LIBGOSTCLSHARED_EXPORT
    Encrypt (const char * data,
             char *result,
             int mode,
             char * errorStr)
{
    if ((0 == data) ||
        (0 == result) )
    {
        if (errorStr != 0)
        {
            std::string error = GetErrorMessage(5);
            std::copy (error.begin(), error.end(), errorStr);
        }
        return 1;
    }

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
        if (errorStr != 0)
        {
            std::string error = GetErrorMessage(4);
            std::copy (error.begin(), error.end(), errorStr);
        }
        return 1;
        break;
    }

    Crypter gCrypter;

    gCrypter.SetModeOfOperation(operationMode);

    std::string output;
    bool success = gCrypter.Encrypt(std::string(data), output);

    std::copy (output.begin(), output.end(), result);

    if (0 != errorStr)
    {
        std::string error = GetErrorMessage(gCrypter.GetErrorCode());
        std::copy (error.begin(), error.end(), errorStr);
    }

    return ((success == true) ? 0 : 1) ;

}

//------------------------------------------------------------------------------
int LIBGOSTCLSHARED_EXPORT
    Decrypt (const char * data,
             char * result,
             int mode,
             char * errorStr)
{
    if ((0 == data) ||
        (0 == result) )
    {
        if (errorStr != 0)
        {
            std::string error = GetErrorMessage(5);
            std::copy (error.begin(), error.end(), errorStr);
        }
        return 1;
    }

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
        if (errorStr != 0)
        {
            std::string error = GetErrorMessage(4);
            std::copy (error.begin(), error.end(), errorStr);
        }
        return 1;
        break;
    }

    Crypter gCrypter;

    gCrypter.SetModeOfOperation(operationMode);

    std::string output;
    bool success = gCrypter.Decrypt(std::string(data), output);

    std::copy (output.begin(), output.end(), result);

    if (0 != errorStr)
    {
        std::string error = GetErrorMessage(gCrypter.GetErrorCode());
        std::copy (error.begin(), error.end(), errorStr);
    }

    return ((success == true) ? 0 : 1) ;

}

//------------------------------------------------------------------------------
// files operations
//------------------------------------------------------------------------------
int LIBGOSTCLSHARED_EXPORT
    EncryptFile (const char * inputFile,
                 const char * outputFile,
                 int mode,
                 int threads,
                 int threadSize,
                 char * errorStr)
{
    if ((0 == inputFile) ||
        (0 == outputFile) )
    {
        if (errorStr != 0)
        {
            std::string error = GetErrorMessage(5);
            std::copy (error.begin(), error.end(), errorStr);
        }
        return 1;
    }

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
        if (errorStr != 0)
        {
            std::string error = GetErrorMessage(4);
            std::copy (error.begin(), error.end(), errorStr);
        }
        return 1;
        break;
    }

    Crypter gCrypter;

    gCrypter.SetModeOfOperation(operationMode);
    gCrypter.SetThreadsCount(threads);
    gCrypter.SetThreadsSize(threadSize);

    bool success = gCrypter.Encrypt(std::string(inputFile), std::string(outputFile));

    if (0 != errorStr)
    {
        std::string error = GetErrorMessage(gCrypter.GetErrorCode());
        std::copy (error.begin(), error.end(), errorStr);
    }

    return ((success == true) ? 0 : 1) ;
}


//------------------------------------------------------------------------------
int LIBGOSTCLSHARED_EXPORT
    DecryptFile (const char * inputFile,
                 const char * outputFile,
                 int mode,
                 int threads,
                 int threadSize,
                 char * errorStr)
{
    if ((0 == inputFile) ||
        (0 == outputFile) )
    {
        if (errorStr != 0)
        {
            std::string error = GetErrorMessage(5);
            std::copy (error.begin(), error.end(), errorStr);
        }
        return 1;
    }

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
        if (errorStr != 0)
        {
            std::string error = GetErrorMessage(4);
            std::copy (error.begin(), error.end(), errorStr);
        }
        return 1;
        break;
    }

    Crypter gCrypter;

    gCrypter.SetModeOfOperation(operationMode);
    gCrypter.SetThreadsCount(threads);
    gCrypter.SetThreadsSize(threadSize);

    bool success = gCrypter.Decrypt(std::string(inputFile), std::string(outputFile));

    if (0 != errorStr)
    {
        std::string error = GetErrorMessage(gCrypter.GetErrorCode());
        std::copy (error.begin(), error.end(), errorStr);
    }

    return ((success == true) ? 0 : 1) ;
}

