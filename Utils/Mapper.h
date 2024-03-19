//
// Created by Norik Saroyan on 17.03.24.
//

#ifndef BMSTU_CHATBOT_2SEM_MAPPER_H
#define BMSTU_CHATBOT_2SEM_MAPPER_H

#include "../User/User.h"
class Mapper{
public:
    string mapToString(User user);
    User mapToObject(string line);
};

#endif //BMSTU_CHATBOT_2SEM_MAPPER_H
