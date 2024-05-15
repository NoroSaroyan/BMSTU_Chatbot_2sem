#include "UserMapper.h"

string UserMapper::mapToString(User user) {
    return
            user.getId() + " " +
            user.getUsername() + " " +
            user.getPassword() + " " +
            user.getAuthority();
}

User UserMapper::mapToObject(std::string line) {
    vector<std::string> values;
    string data;

    for (char c : line) {
        if (c != ' ') {
            data += c;
        } else {
            values.push_back(data);
            data = "";
        }
    }

    values.push_back(data);

    User temp;
    if (values.size() >= 4) {
        temp.setId(values[0]);
        temp.setUsername(values[1]);
        temp.setPassword(values[2]);
        temp.setAuthority(values[3]);
    }

    return temp;
}
