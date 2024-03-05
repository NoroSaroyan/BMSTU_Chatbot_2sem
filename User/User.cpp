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

string User::getUsernane() {
    return this->username;
}

string User::getPassword() {
    return this->password;
}

void User::setUsername(string username) {
    this->username = move(username);
}

void User::setPassword(string password) {
    this->password = move(password);
}


