
#include "User.h"
#include "../Headers.h"

using namespace std;
void registerUser() {
    User temp;
    string username,password;
    cin>>username;
    temp.setUsername(username);
    cin>>password;
    temp.setPassword(password);
}
