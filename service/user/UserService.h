//
// Created by Norik Saroyan on 05.03.24.
//

#ifndef BMSTU_CHATBOT_2SEM_USERSERVICE_H
#define BMSTU_CHATBOT_2SEM_USERSERVICE_H

#include "../../Entity/User/User.h"
#include "../../Utils/Utilities.h"
#include "../../Utils/user/UserMapper.h"
#include "fstream"
#include "iostream"
#include "../../AuthManager.h"

class UserService {
private:
    Utilities utils;
    UserMapper mapper;
public :
    void registerAccount(string username, string password);

    optional<User> login(string username, string password);
};

#endif //BMSTU_CHATBOT_2SEM_USERSERVICE_H
