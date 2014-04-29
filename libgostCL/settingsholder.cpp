#include "settingsholder.h"

SettingsHolder::SettingsHolder()
    : customSBoxesSet (false)
{
//  OID: 1.2.643.2.2.31.1   id-GostR3411-94-TestParamSet
    std::vector <int> line;
    line.reserve(16);
    sboxes.reserve(8);

    line = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
    sboxes.push_back(line);
    line = { 4, 10, 9, 2, 13, 8, 0, 14, 6, 11, 1, 12, 7, 15, 5, 3 };
    sboxes.push_back(line);
    line = { 14, 11, 4, 12, 6, 13, 15, 10, 2, 3, 8, 1, 0, 7, 5, 9 };
    sboxes.push_back(line);
    line = { 5, 8, 1, 13, 10, 3, 4, 2, 14, 15, 12, 7, 6, 0, 9, 13 };
    sboxes.push_back(line);
    line = { 7, 13, 10, 1, 0, 8, 9, 15, 14, 4, 6, 12, 11, 2, 5, 3 };
    sboxes.push_back(line);
    line = { 6, 12, 7, 1, 5, 15, 13, 8, 4, 10, 9, 14, 0, 3, 11, 2 };
    sboxes.push_back(line);
    line = { 4, 11, 10, 0, 7, 2, 1, 13, 3, 6, 8, 5, 9, 12, 15, 14 };
    sboxes.push_back(line);
    line = { 13, 11, 4, 1, 3, 15, 5, 9, 0, 10, 14, 7, 6, 8, 2, 12 };
    sboxes.push_back(line);
    line = { 1, 15, 13, 0, 5, 7, 10, 4, 9, 2, 3, 14, 6, 11, 8, 12 };
    sboxes.push_back(line);


}
