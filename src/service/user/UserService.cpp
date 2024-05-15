#include "UserService.h"
#include <iostream>
#include <fstream>

using namespace std;

void UserService::registerAccount(string username, string password) {
    User temp;
    while (!utils.checkEmail(username)) {
        cout << "Email is invalid, try again: ";
        cin >> username;
        cout << endl;
    }
    temp.setUsername(username);

    cout << "Enter password" << endl;
    cin >> password;
    cout << endl;
    while (!utils.checkPassword(password)) {
        cout << "Password is too weak, try again: ";
        cin >> password;
        cout << endl;
    }

    temp.setPassword(password);
    temp.setAuthority("USER");

    boost::uuids::random_generator generator;
    boost::uuids::uuid uuid = generator();
    temp.setId(to_string(uuid));

    ofstream out(this->path, ios::app);
    if (out.is_open()) {
        out << mapper.mapToString(temp) << "\n";
    } else {
        cout << "Something went wrong" << endl;
    }
}

optional<User> UserService::login(string username, string password) {
    User currentUser;

    ifstream file(this->path, ios::in);
    if (!file.is_open()) {
        cout << "Internal server error, couldn't access database" << endl;
    }

    string current;

    while (getline(file, current)) {
        currentUser = mapper.mapToObject(current);
        if (currentUser.getUsername() == username && currentUser.getPassword() == password) {
            AuthManager::getInstance().login(username, password, currentUser.getAuthority());
            return currentUser;
        }
    }
    file.close();
    cout << "User not found, try again" << endl;
    return nullopt;
}
