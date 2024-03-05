#include "../User/User.h"
#include "../Headers.h"

string mapToString(User user) {
    return
            user.getId() + " " +
            user.getUsername() + " " +
            user.getPassword() + " " +
            user.getAuthority();
}
User mapToObject(string line){
    vector<string> values = {};
    for (int i = 0; i < line.length(); ++i) {
        string data;
        if(line[i] != ' '){
            data+=line[i];
        }else{
            values.at(i) = data;
            data = "";
        }
    }
    User temp;
    temp.setId(values.at(0));
}
