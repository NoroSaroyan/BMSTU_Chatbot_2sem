#ifndef USER_H
#define USER_H

#include "../../Headers.h"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

class User {
public:

    User(const string &username, const string &password, const string &authority);

    User();

    string getUsername();

    string getPassword();

    string getId();

    string getAuthority();

    void setUsername(const string &username);

    void setPassword(const string &password);

    void setAuthority(string authority);

    void setId(string id);

private:
    string username;
    string password;
    string authority;
    string id;
};


#endif //USER_H
