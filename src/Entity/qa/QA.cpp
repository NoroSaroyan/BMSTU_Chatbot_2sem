
#include "QA.h"

QA::QA(const string &question, const string &answer){
    boost::uuids::random_generator generator;
    boost::uuids::uuid uuid = generator();
    this->setId(to_string(uuid));
    this->setQuestion(question);
    this->setAnswer(answer);
}
