#ifndef SETTINGSHOLDER_H
#define SETTINGSHOLDER_H

#include <vector>
#include <string>

#if defined (_MSC_VER)
#define DELETED_MEMBER
#elif defined(__GNUC__) || defined(__GNUG__)
#define DELETED_MEMBER =delete
#endif


class SettingsHolder
{
public:
    //singleton pattern: {
    static const SettingsHolder& Instance()
           {
                   static SettingsHolder theSingleInstance;
                   return theSingleInstance;
           }
    // } singleton

    enum SBoxesID
    {
        id_GostR3411_94_TestParamSet,
        // defined in Gost R 34.11-94 as testing
        //used in Cental Bank RF

        id_Gost28147_89_CryptoPro_A_ParamSet,
        //OID: 1.2.643.2.2.31.1
        //CryptoPRO CSP default, "Верба-О" default

        id_Gost28147_89_CryptoPro_B_ParamSet,
        //OID: 1.2.643.2.2.31.2
        //used in CryptoPRO CSP

        id_Gost28147_89_CryptoPro_C_ParamSet,
        //OID: 1.2.643.2.2.31.3
        //used in CryptoPRO CSP

        id_Gost28147_89_CryptoPro_D_ParamSet,
        //OID: 1.2.643.2.2.31.4
        //used in CryptoPRO CSP

        id_tc26_gost_28147_param_A
        //OID: 1.2.643.7.1.2.5.1.1
        //recomended for developers
        //was sugested for ISO/IEC 18033-3 (international standartisation attempt of gost)
    }; //enum

    bool SetSBoxes (std::vector <std::vector <int> > & boxes);
    bool SetStandartSBoxes (SBoxesID idSet = id_GostR3411_94_TestParamSet);

    std::vector <std::vector <int> > GetSBoxes () const;

    static std::vector <std::vector <int> >
        GetStandartSBoxes (SBoxesID idSet = id_GostR3411_94_TestParamSet);

    bool SetKey (const std::string & key);
    std::string GetKey () const;

    int GetErrorCode ();

private:
    SettingsHolder();
    ~SettingsHolder();

    //disable copy
    SettingsHolder (const SettingsHolder &) DELETED_MEMBER;
    SettingsHolder &operator=(const SettingsHolder &) DELETED_MEMBER;

    bool customSBoxesSet;
    std::string encryptionKey;
    std::vector <std::vector <int> > sboxes;
    bool lastError;
};

#endif // SETTINGSHOLDER_H
