//
// Created by Norik Saroyan on 15.05.24.
//

#ifndef BMSTU_CHATBOT_2SEM_HISTORYSERVICE_H
#define BMSTU_CHATBOT_2SEM_HISTORYSERVICE_H


#include "../qa/QAService.h"
#include "../user/UserService.h"
#include "fstream"

class HistoryService {
private:
    string pathPrefix = "/Users/noriksaroyan/CLionProjects/BMSTU-Chatbot-2sem/static/Database/history";
public:
    string createRecord(string userId, QA qa, tm time);

    void postRecord(string userID, string record);

};


#endif //BMSTU_CHATBOT_2SEM_HISTORYSERVICE_H
