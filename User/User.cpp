//
// Created by Norik Saroyan on 01.03.24.
//


#include "User.h"

#include <utility>

string User::getAuthority() {
    return this->authority;
}

string User::getId() {
    return this->id;
}

string User::getUsername() {
    return this->username;
}

string User::getPassword() {
    return this->password;
}

void User::setUsername(string username) {
    this->username = std::move(username);
}

void User::setPassword(string password) {
    this->password = std::move(password);
}

void User::setAuthority() {
    this->authority = "USER";
}
void User::setId(basic_string<char> basicString) {
    this->id = 1;
}
