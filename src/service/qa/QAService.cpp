//
// Created by Norik Saroyan on 15.05.24.
//

#include "QAService.h"


optional<vector<QA>> QAService::getAll() {
    ifstream inFile(this->path);
    if (!inFile) {
        std::cerr << "Unable to open file for reading." << std::endl;
        return nullopt;
    }

    std::vector<QA> readQuestions;
    std::string line;
    while (std::getline(inFile, line)) {
        QA qa = this->mapper.mapToObject(line);
        readQuestions.push_back(qa);
    }

    inFile.close();
    return readQuestions;
}

optional<QA> QAService::getById(std::string id) {
    ifstream inFile(this->path);
    if (inFile) {
        string line;
        while (std::getline(inFile, line)) {
            QA qa = this->mapper.mapToObject(line);
            if (qa.getId() == id) {
                return qa;
            }
        }
    }
    if (!inFile) {
        std::cerr << "Unable to open file for reading." << std::endl;
    }
    return nullopt;
}