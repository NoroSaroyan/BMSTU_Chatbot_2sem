#include "Menu/Menu.h"
#include "Menu/MenuItem.h"
#include "User/UserServices.h"

using namespace std;

#pragma region функции-заглушки


User global;


int request();
int loginFunction();
int registration();
int questions();
int dataStoringGuide();
int privacyPolicy();
int main();
UserServices service;
int request() {
    int result = 1;
    int number, power;
    cout << "Введите число" << endl;
    cin >> number;
    cout << "\n введите степень" << endl;
    cin >> power;
    for (int i = 0; i < power; i++) {
        result *= number;
    }
    cout<<"\n"<<result<<endl;
    return 1;
}

int loginFunction() {
    User temp = service.login();
    if(temp.getUsername() != ""){

    }
    return 1;
}

int registration() {
    cout << "REGISTRATION"<<endl;
    service.registerAccount();
    return 2;
}

int questions() {
    cout << "This will show you every question out bot can answer...\n\n";
    return 3;
}

int dataStoringGuide() {
    cout <<
            "We take your safety close to heart, "
            "\nso, we came up with the idea of multilayer encoding, "
            "\nto ensure your private information and "
            "\n4search history can't be read by anyone except you.\n\n";
    return 4;
}

int privacyPolicy() {
    cout <<
            "Privacy policy is for telling you about basic rules and agreements between me and you."
            "\n we'll get to this in a bit. \n\n";
    return 5;
}
#pragma endregion

const int ITEMS_NUMBER = 6;


int main() {
    UserServices service;
    MenuItem items[ITEMS_NUMBER]{
        MenuItem{"Request", request}, {"Login", loginFunction}, MenuItem{"Register", registration},
        MenuItem{"Catalog", questions},
        MenuItem{"How do we store data?", dataStoringGuide}, MenuItem{"Privacy policy", privacyPolicy}
    };
    Menu menu("My console menu", items, ITEMS_NUMBER);
    while (menu.runCommand()) {
    };

    return 0;
}
