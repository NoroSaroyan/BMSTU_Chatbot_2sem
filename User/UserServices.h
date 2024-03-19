//
// Created by Norik Saroyan on 05.03.24.
//

#ifndef BMSTU_CHATBOT_2SEM_USERSERVICES_H
#define BMSTU_CHATBOT_2SEM_USERSERVICES_H

#include "User.h"
#include "../Utils/Utilities.h"
#include "../Utils/Mapper.h"
#include "fstream"
#include "iostream"

class UserServices {
public :
    void registerAccount();

    void login();
};

#endif //BMSTU_CHATBOT_2SEM_USERSERVICES_H
