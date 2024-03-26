
#include "UserServices.h"

using namespace std;

Utilities utils;
Mapper mapper;

void UserServices::registerAccount() {
    User temp;
    string username, password;
    cout << endl;

    cout << "Enter email" << endl;
    cin >> username;
    cout << endl;
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

    ifstream file("/Users/noriksaroyan/CLionProjects/BMSTU-Chatbot-2sem/Database/users.txt", ios::in);
    string line;
    int count = 0;

    if (file.is_open()) {
        while (getline(file, line)) {
            count++;
        }
        file.close();
    }

    temp.setPassword(password);
    temp.setAuthority("USER");
    temp.setId(to_string(count + 1));

    ofstream out("/Users/noriksaroyan/CLionProjects/BMSTU-Chatbot-2sem/Database/users.txt", ios::app);
    if (out.is_open()) {
        out << mapper.mapToString(temp) << "\n";;
    } else {
        cout << "Something went wrong" << endl;
    }
}

User UserServices::login() {
    User currentUser;
    string username, password;
    cout << "Enter email" << endl;
    cin >> username;
    cout << endl;
    cout << "Enter password" << endl;
    cin >> password;

    ifstream file("/Users/noriksaroyan/CLionProjects/BMSTU-Chatbot-2sem/Database/users.txt", ios::in);
    if (!file.is_open()) {
        cout << "Internal server error, couldn't access database" << endl;
    }

    string current;

    while (getline(file, current)) {
        currentUser = mapper.mapToObject(current);
        if (currentUser.getUsername() == username && currentUser.getPassword() == password) {
            return currentUser;
        }
    }
    file.close();
    cout << "User not found, try again" << endl;
    return currentUser;
}
