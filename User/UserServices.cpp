
#include "UserServices.h"

using namespace std;

Utilities utils;
Mapper mapper;

void UserServices::registerAccount() {
    User temp;
    string username, password;
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
    ifstream file("/Users/noriksaroyan/CLionProjects/BMSTU-Chatbot-2sem/Database/users.txt");
    string line;
    int count = 0;

    if (file.is_open()) {
        while (getline(file, line)) {
            count++;
        }

        file.close();
    }
    temp.setPassword(password);
    temp.setAuthority();
    temp.setId(to_string(count + 1));

    ofstream out("/Users/noriksaroyan/CLionProjects/BMSTU-Chatbot-2sem/Database/users.txt");
    if (out.is_open()) {
        out << mapper.mapToString(temp);
    } else {
        cout << "Something went wrong" << endl;
    }
}

void UserServices::login(string username, string password) {
    ifstream file("users.txt", ios_base::in);
    if (file.is_open()) {
        while (!file.eof()) {

        }
    }
}
