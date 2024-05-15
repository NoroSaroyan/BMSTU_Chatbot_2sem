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

void User::setUsername(const string &username) {
    this->username = username;
}

void User::setPassword(const string &password) {
    this->password = password;
}

void User::setAuthority(string authority) {
    this->authority = std::move(authority);
}

void User::setId(string id) {
    this->id = id;
}

User::User(const string &username, const string &password, const string &authority) {
    boost::uuids::random_generator generator;
    boost::uuids::uuid uuid = generator();
    this->setId(to_string(uuid));
    this->setUsername(username);
    this->setPassword(password);
    this->setAuthority(authority);
}

User::User() {}
