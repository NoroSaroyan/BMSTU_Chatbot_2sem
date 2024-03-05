#include "../Headers.h"
#include "regex"
using namespace std;

string emailRegex = "^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\\.[a-zA-Z0-9-.]+$";
string passwordRegex = "^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[!@#$%^&*])[A-Za-z\\d!@#$%^&*]{8,}$";

bool checkEmail(const string& email){
    return regex_match(email, regex(emailRegex));
}
bool checkPassword(const string& password){
    return regex_match(password, regex(passwordRegex));
}