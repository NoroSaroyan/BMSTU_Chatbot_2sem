#include "HistoryService.h"

string HistoryService::createRecord(string userId, QA qa, time_t time) {
    History temp(userId, qa, time);
    auto result = historyMapper.mapToString(temp);
    postRecord(userId, result);
}

void HistoryService::postRecord(string userId, string record) {
    ofstream out(pathPrefix + userId);
    if (!out.is_open()) {
        cerr << "Database error";
    }
    out << record << endl;
}
