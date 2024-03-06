//
// Created by Norik Saroyan on 05.03.24.
//

#ifndef BMSTU_CHATBOT_2SEM_USERSERVICES_H
#define BMSTU_CHATBOT_2SEM_USERSERVICES_H

#include "User.h"
#include "../Utils/Utilities.cpp"
#include "fstream"
#include "iostream"

class UserServices {
    void registerAccount();
    void login(string username, string password);
    };
#endif //BMSTU_CHATBOT_2SEM_USERSERVICES_H
