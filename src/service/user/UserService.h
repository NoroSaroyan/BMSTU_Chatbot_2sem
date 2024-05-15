//
// Created by Norik Saroyan on 05.03.24.
//

#ifndef BMSTU_CHATBOT_2SEM_USERSERVICE_H
#define BMSTU_CHATBOT_2SEM_USERSERVICE_H

#include "../../Entity/user/User.h"
#include "../../helpers/utils/Utilities.h"
#include "../../helpers/mappers/user/UserMapper.h"
#include "fstream"
#include "iostream"
#include "../../auth/AuthManager.h"

class UserService {
private:
    string path = "/Users/noriksaroyan/CLionProjects/BMSTU-Chatbot-2sem/static/Database/users.txt";
    Utilities utils;
    UserMapper mapper;
public :
    void registerAccount(string username, string password);

    optional<User> login(string username, string password);
};

#endif //BMSTU_CHATBOT_2SEM_USERSERVICE_H
