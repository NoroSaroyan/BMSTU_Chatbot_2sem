using namespace std;
#include "random"
#include "Utilities.h"

bool Utilities::checkEmail(const std::string &email) {
    return regex_match(email, regex(this->getEmailRegex()));
}

bool Utilities::checkPassword(const std::string &password) {
    return regex_match(password, regex(this->getPasswordRegex()));
}

const string &Utilities::getEmailRegex() const {
    return emailRegex;
}

const string &Utilities::getPasswordRegex() const {
    return passwordRegex;
}

const string &Utilities::generateNumericID() const {
    std::string id;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, 9);

    for (int i = 0; i < 8; ++i) {
        id += std::to_string(distribution(gen));
    }

    return id;
}