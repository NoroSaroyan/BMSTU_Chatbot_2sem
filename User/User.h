//
// Created by Norik Saroyan on 01.03.24.
//
#ifndef USER_H
#define USER_H

#include "../Headers.h"

class User {
public:
    string getUsername();

    string getPassword();

    string getId();

    string getAuthority();

    void setUsername(string username);

    void setPassword(string password);

    void setAuthority();

    void setId(basic_string<char> basicString);

private:
    string username;
    string password;
    string authority;
    string id;
};



#endif //USER_H
