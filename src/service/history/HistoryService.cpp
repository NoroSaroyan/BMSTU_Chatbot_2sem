//
// Created by Norik Saroyan on 15.05.24.
//

#include "HistoryService.h"

string HistoryService::createRecord(string userId, QA qa, tm time) {
    QAMapper mapper;
    string result;
    result += userId+" | ";
    result += mapper.mapToString(qa) + " | ";
    char buffer[20]; // Buffer to hold the formatted time string
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", time);

    result += time + " | ";
    return result;
}

void HistoryService::postRecord(string userId, string record) {

}
