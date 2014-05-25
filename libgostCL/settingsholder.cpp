#include "settingsholder.h"

SettingsHolder::SettingsHolder()
    : customSBoxesSet (false)
    , lastError (0)
{
}

SettingsHolder::~SettingsHolder()
{

}

std::string SettingsHolder::GetKey() const
{
    return encryptionKey;
}

int SettingsHolder::GetErrorCode()
{
    lastError = 0;
    return lastError;
}

std::vector<std::vector<C_U8> > SettingsHolder::GetSBoxes() const
{
    if (customSBoxesSet)
    {
        return sboxes;
    }
    else
    {
        return GetStandartSBoxes();
    }
}

std::vector <std::vector <C_U8> >
    SettingsHolder::GetStandartSBoxes (SBoxesID idSet)
{
    std::vector <std::vector <C_U8> > boxes;
    std::vector <C_U8> line;
    line.reserve(16);
    boxes.reserve(8);

    switch (idSet)
    {
    case id_Gost28147_89_CryptoPro_A_ParamSet:
        line = { 9, 6, 3, 2, 8, 11, 1, 7, 10, 4, 14, 15, 12, 0, 13, 5 };
        boxes.push_back(line);
        line = { 3, 7, 14, 9, 8, 10, 15, 0, 5, 2, 6, 12, 11, 4, 13, 1 };
        boxes.push_back(line);
        line = { 14, 4, 6, 2, 11, 3, 13, 8, 12, 15, 5, 10, 0, 7, 1, 9 };
        boxes.push_back(line);
        line = { 14, 7, 10, 12, 13, 1, 3, 9, 0, 2, 11, 4, 15, 8, 5, 6 };
        boxes.push_back(line);
        line = { 11, 5, 1, 9, 8, 13, 15, 0, 14, 4, 2, 3, 12, 7, 10, 6 };
        boxes.push_back(line);
        line = { 3, 10, 13, 12, 1, 2, 0, 11, 7, 5, 9, 4, 8, 15, 14, 6 };
        boxes.push_back(line);
        line = { 1, 13, 2, 9, 7, 10, 6, 0, 8, 12, 4, 5, 15, 3, 11, 14 };
        boxes.push_back(line);
        line = { 11, 10, 15, 5, 0, 12, 14, 8, 6, 2, 3, 9, 1, 7, 13, 4 };
        break;

    case id_Gost28147_89_CryptoPro_B_ParamSet:
        line = { 8, 4, 11, 1, 3, 5, 0, 9, 2, 14, 10, 12, 13, 6, 7, 15 };
        boxes.push_back(line);
        line = { 0, 1, 2, 10, 4, 13, 5, 12, 9, 7, 3, 15, 11, 8, 6, 14 };
        boxes.push_back(line);
        line = { 14, 12, 0, 10, 9, 2, 13, 11, 7, 5, 8, 15, 3, 6, 1, 4 };
        boxes.push_back(line);
        line = { 7, 5, 0, 13, 11, 6, 1, 2, 3, 10, 12, 15, 4, 14, 9, 8 };
        boxes.push_back(line);
        line = { 2, 7, 12, 15, 9, 5, 10, 11, 1, 4, 0, 13, 6, 8, 14, 3 };
        boxes.push_back(line);
        line = { 8, 3, 2, 6, 4, 13, 14, 11, 12, 1, 7, 15, 10, 0, 9, 5 };
        boxes.push_back(line);
        line = { 5, 2, 10, 11, 9, 1, 12, 3, 7, 4, 13, 0, 6, 15, 8, 14 };
        boxes.push_back(line);
        line = { 0, 4, 11, 14, 8, 3, 7, 1, 10, 2, 9, 6, 15, 13, 5, 12 };
        break;

    case id_Gost28147_89_CryptoPro_C_ParamSet:
        line = { 1, 11, 12, 2, 9, 13, 0, 15, 4, 5, 8, 14, 10, 7, 6, 3 };
        boxes.push_back(line);
        line = { 0, 1, 7, 13, 11, 4, 5, 2, 8, 14, 15, 12, 9, 10, 6, 3 };
        boxes.push_back(line);
        line = { 8, 2, 5, 0, 4, 9, 15, 10, 3, 7, 12, 13, 6, 14, 1, 11 };
        boxes.push_back(line);
        line = { 3, 6, 0, 1, 5, 13, 10, 8, 11, 2, 9, 7, 14, 15, 12, 4 };
        boxes.push_back(line);
        line = { 8, 13, 11, 0, 4, 5, 1, 2, 9, 3, 12, 14, 6, 15, 10, 7 };
        boxes.push_back(line);
        line = { 12, 9, 11, 1, 8, 14, 2, 4, 7, 3, 6, 5, 10, 0, 15, 13 };
        boxes.push_back(line);
        line = { 10, 9, 6, 8, 13, 14, 2, 0, 15, 3, 5, 11, 4, 1, 12, 7 };
        boxes.push_back(line);
        line = { 7, 4, 0, 5, 10, 2, 15, 14, 12, 6, 1, 11, 13, 9, 3, 8 };
        break;

    case id_Gost28147_89_CryptoPro_D_ParamSet:
        line = { 15, 12, 2, 10, 6, 4, 5, 0, 7, 9, 14, 13, 1, 11, 8, 3 };
        boxes.push_back(line);
        line = { 11, 6, 3, 4, 12, 15, 14, 2, 7, 13, 8, 0, 5, 10, 9, 1 };
        boxes.push_back(line);
        line = { 1, 12, 11, 0, 15, 14, 6, 5, 10, 13, 4, 8, 9, 3, 7, 2 };
        boxes.push_back(line);
        line = { 1, 5, 14, 12, 10, 7, 0, 13, 6, 2, 11, 4, 9, 3, 15, 8 };
        boxes.push_back(line);
        line = { 0, 12, 8, 9, 13, 2, 10, 11, 7, 3, 6, 5, 4, 14, 15, 1 };
        boxes.push_back(line);
        line = { 8, 0, 15, 3, 2, 5, 14, 11, 1, 10, 4, 7, 12, 9, 13, 6 };
        boxes.push_back(line);
        line = { 3, 0, 6, 15, 1, 14, 9, 2, 13, 8, 12, 4, 11, 10, 5, 7 };
        boxes.push_back(line);
        line = { 1, 10, 6, 8, 15, 11, 0, 4, 12, 3, 5, 9, 7, 13, 2, 14 };
        break;

    case id_tc26_gost_28147_param_A:
        line = { 12, 4, 6, 2, 10, 5, 11, 9, 14, 8, 13, 7, 0, 3, 15, 1 };
        boxes.push_back(line);
        line = { 6, 8, 2, 3, 9, 10, 5, 12, 1, 14, 4, 7, 11, 13, 0, 15 };
        boxes.push_back(line);
        line = { 11, 3, 5, 8, 2, 15, 10, 13, 14, 1, 7, 4, 12, 9, 6, 0 };
        boxes.push_back(line);
        line = { 12, 8, 2, 1, 13, 4, 15, 6, 7, 0, 10, 5, 3, 14, 9, 11 };
        boxes.push_back(line);
        line = { 7, 15, 5, 10, 8, 1, 6, 13, 0, 9, 3, 14, 11, 4, 2, 12 };
        boxes.push_back(line);
        line = { 5, 13, 15, 6, 9, 2, 12, 10, 11, 7, 8, 1, 4, 3, 14, 0 };
        boxes.push_back(line);
        line = { 8, 14, 2, 5, 6, 9, 1, 12, 15, 4, 11, 0, 13, 10, 3, 7 };
        boxes.push_back(line);
        line = { 1, 7, 14, 13, 0, 5, 8, 3, 4, 15, 10, 6, 9, 12, 11, 2 };
        break;

    case id_GostR3411_94_TestParamSet:
    default:
        line = { 4, 10, 9, 2, 13, 8, 0, 14, 6, 11, 1, 12, 7, 15, 5, 3 };
        boxes.push_back(line);
        line = { 14, 11, 4, 12, 6, 13, 15, 10, 2, 3, 8, 1, 0, 7, 5, 9 };
        boxes.push_back(line);
        line = { 5, 8, 1, 13, 10, 3, 4, 2, 14, 15, 12, 7, 6, 0, 9, 13 };
        boxes.push_back(line);
        line = { 7, 13, 10, 1, 0, 8, 9, 15, 14, 4, 6, 12, 11, 2, 5, 3 };
        boxes.push_back(line);
        line = { 6, 12, 7, 1, 5, 15, 13, 8, 4, 10, 9, 14, 0, 3, 11, 2 };
        boxes.push_back(line);
        line = { 4, 11, 10, 0, 7, 2, 1, 13, 3, 6, 8, 5, 9, 12, 15, 14 };
        boxes.push_back(line);
        line = { 13, 11, 4, 1, 3, 15, 5, 9, 0, 10, 14, 7, 6, 8, 2, 12 };
        boxes.push_back(line);
        line = { 1, 15, 13, 0, 5, 7, 10, 4, 9, 2, 3, 14, 6, 11, 8, 12 };
        boxes.push_back(line);
        break;
    }

    return boxes;
}

bool SettingsHolder::SetKey(const std::string &key)
{
    lastError = 0;
    encryptionKey = key;
    return true;
}

bool SettingsHolder::SetStandartSBoxes(SBoxesID idSet)
{
    lastError = 0;
    sboxes.clear();
    sboxes = GetStandartSBoxes(idSet);
    customSBoxesSet = true;

    return true;
}

bool SettingsHolder::SetSBoxes(const std::vector<std::vector<C_U8> > &boxes)
{
    lastError = 1;
    if (boxes.size() != 8)
    {
        return false;
    }

    for (size_t i=0; i<boxes.size(); i++)
    {
        if (boxes.at(i).size() != 16)
        {
            return false;
        }
    }

    for (size_t i=0; i<boxes.size(); i++)
    {
        bool errorLine = false;
        std::vector <bool> elements = { false, false, false, false,
                                        false, false, false, false,
                                        false, false, false, false,
                                        false, false, false, false };

        for (size_t j=0; j<boxes.at(i).size(); j++)
        {
            if ( errorLine )
            {
                break;
            }

            if (( boxes.at(i).at(j) > 15) ||
                ( boxes.at(i).at(j) <  0) )
            {
                return false;
            }

            if (elements.at( boxes.at(i).at(j) ))
            {
                elements.at( boxes.at(i).at(j) ) = true;
            }
            else
            {
                errorLine = true;
                break;
            }
        }

        if (errorLine)
        {
            return false;
        }
    }

    sboxes.clear();
    sboxes = boxes;
    customSBoxesSet = true;
    lastError = 0;
    return true;
}
