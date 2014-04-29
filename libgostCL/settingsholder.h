#ifndef SETTINGSHOLDER_H
#define SETTINGSHOLDER_H

#include <list>
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

    bool SetSBoxes (std::vector <std::vector <int> > & sboxes);
    bool SetSboxes (const std::string & idSet);
    std::list <std::list <int> > GetSBoxes () const;

    bool SetKey (const std::string & key);
    std::string GetKey () const;

private:
    SettingsHolder();
    ~SettingsHolder();

    //disable copy
    SettingsHolder (const SettingsHolder &) DELETED_MEMBER;
    SettingsHolder &operator=(const SettingsHolder &) DELETED_MEMBER;

    bool customSBoxesSet;
    std::string encryptionKey;
    std::vector <std::vector <int> > sboxes;
};

#endif // SETTINGSHOLDER_H
