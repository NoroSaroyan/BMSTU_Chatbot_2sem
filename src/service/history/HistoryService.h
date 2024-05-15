//
// Created by Norik Saroyan on 15.05.24.
//

#ifndef BMSTU_CHATBOT_2SEM_HISTORYSERVICE_H
#define BMSTU_CHATBOT_2SEM_HISTORYSERVICE_H


#include "../qa/QAService.h"
#include "../user/UserService.h"
#include "fstream"
#include "../../helpers/mappers/history/HistoryMapper.h"

class HistoryService {
private:
    string pathPrefix = "/Users/noriksaroyan/CLionProjects/BMSTU-Chatbot-2sem/static/Database/history";
    HistoryMapper historyMapper;
public:
    string createRecord(string userId, QA qa, time_t time);

    void postRecord(string userID, string record);

};


#endif //BMSTU_CHATBOT_2SEM_HISTORYSERVICE_H
