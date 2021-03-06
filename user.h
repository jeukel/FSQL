#ifndef USER_H
#define USER_H
#include "SimpleList.h"

class user
{
public:
    user();
    bool CanWrite(string pFileName);
    bool CanRead(string pFileName);
    string getUsername();
    void setUserName(string pNewName);
    void addToWrite(string pFileName);
    void addToRead(string pFileName);

private:
    string _userName;
    SimpleList<char*>* _ReadOnlyDBS;
    SimpleList<char*>* _WriteDBS;
};

#endif // USER_H
