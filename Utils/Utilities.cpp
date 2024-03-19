using namespace std;

#include "Utilities.h"

bool Utilities::checkEmail(const std::string &email) {
    return regex_match(email, regex(this->getEmailRegex()));
}

bool Utilities::checkPassword(const std::string &password) {
    return true;
//    return regex_match(password, regex(this->getPasswordRegex()));
}

const string &Utilities::getEmailRegex() const {
    return emailRegex;
}

const string &Utilities::getPasswordRegex() const {
    return passwordRegex;
}
