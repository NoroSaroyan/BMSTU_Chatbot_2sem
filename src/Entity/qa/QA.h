//
// Created by Norik Saroyan on 14.05.24.
//

#ifndef BMSTU_CHATBOT_2SEM_QA_H
#define BMSTU_CHATBOT_2SEM_QA_H

#include "../../../Headers.h"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

class QA {
private:
    string id;
    string question;
    string answer;

public:
    QA(const string &question, const string &answer);

    void setId(string id) {
        this->id = id;
    }

    void setQuestion(string question) {
        this->question = question;
    }

    void setAnswer(string answer) {
        this->answer = answer;
    }

    string getId() {
        return this->id;
    }

    string getQuestion() {
        return this->question;
    }

    string getAnswer() {
        return this->answer;
    }
};

#endif //BMSTU_CHATBOT_2SEM_QA_H
