#include "QAService.h"

std::optional<MyGenericVector<QA>> QAService::getAll() {
    std::ifstream inFile = openInputFile();
    if (!inFile) {
        return std::nullopt;
    }

    MyGenericVector<QA> readQuestions;
    std::string line;
    while (std::getline(inFile, line)) {
        QA qa = mapper.mapToObject(line);
        readQuestions.push_back(qa);
    }

    inFile.close();
    return readQuestions;
}
optional<QA> QAService::getById(const std::string &id) {
    ifstream inFile = openInputFile();
    if (inFile) {
        std::string line;
        while (getline(inFile, line)) {
            QA qa = mapper.mapToObject(line);
            if (qa.getId() == id) {
                return qa;
            }
        }
    }
    return std::nullopt;
}
