#include "UserServices.h"

using namespace std;

void UserServices::registerAccount() {
    User temp;
    string username, password;

    cin >> username;
    while (!checkEmail(username)) {
        cout << "Email is invalid, try again: ";
        cin >> username;
        cout << endl;
    }
    temp.setUsername(username);

    cin >> password;
    while (!checkPassword(password)) {
        cout << "Password is too weak, try again: ";
        cin >> password;
        cout << endl;
    }
    ifstream file("users.txt");
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
    temp.setId(basic_string<char>());

    ofstream out("users.txt");
    if (out.is_open()) {
        out << temp.toString();
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
