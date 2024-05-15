//
// Created by Norik Saroyan on 15.05.24.
//

#ifndef BMSTU_CHATBOT_2SEM_QASERVICE_H
#define BMSTU_CHATBOT_2SEM_QASERVICE_H

#include "fstream"
#include "../../Utils/qa/QAMapper.h"
#include "../../Entity/qa/QA.h"

class QAService {
private:
    QAMapper mapper;
    string path = "/Users/noriksaroyan/CLionProjects/BMSTU-Chatbot-2sem/Database/QA.txt";
public:

    optional<vector<QA>> getAll();

    optional<QA> getById(string id);

};


#endif //BMSTU_CHATBOT_2SEM_QASERVICE_H
