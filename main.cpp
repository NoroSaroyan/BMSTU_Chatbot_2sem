#include "Menu/Menu.h"
#include "Menu/MenuItem.h"
#include "service/user/UserService.h"
#include "service/qa/QAService.h"
#include "AuthManager.h"
#include "Entity/qa/QA.h"

using namespace std;

void authorizeUser(User user);

[[maybe_unused]]
void logoutUser();

#pragma region функции-заглушки

int request();

int loginFunction();

int registration();

int questions();

int dataStoringGuide();

int privacyPolicy();

int main();

UserService service;

int request() {
    AuthManager &authManager = AuthManager::getInstance();
    auto temp = authManager.getCurrentUser();
    cout << temp->getId();

    int result = 1;
    int number, power;
    cout << "Введите число" << endl;
    cin >> number;
    cout << "\n введите степень" << endl;
    cin >> power;
    for (int i = 0; i < power; i++) {
        result *= number;
    }
    cout << "\n" << result << endl;
    return 1;
}

int loginFunction() {
    string username, password;

    cout << "Enter username" << endl;
    cin >> username;
    cout << endl;

    cout << "Enter password" << endl;
    cin >> password;
    cout << endl;

    if (auto user = service.login(username, password); user.has_value()) authorizeUser(user.value());
    return 1;
}

int registration() {
    cout << "REGISTRATION" << endl;
    string username, password;

    cout << "Enter username" << endl;
    cin >> username;
    cout << endl;

    cout << "Enter password" << endl;
    cin >> password;
    cout << endl;

    service.registerAccount(username, password);
    return 2;
}

int questions() {

    QAService qaService;
    optional<vector<QA>> opt = qaService.getAll();
    vector<QA> list = opt.has_value() ? opt.value() : std::vector<QA>();
    int idx = 1;
    for (auto qa: list) {
        cout << idx << ". " << qa.getQuestion() << endl;
        idx++;
    }
    cout << endl;
    return 3;
}

int dataStoringGuide() {
    AuthManager &authManager = AuthManager::getInstance();
    auto temp = authManager.getCurrentUser();
    cout << temp->getId();

    cout <<
         "We take your safety close to heart, "
         "\nso, we came up with the idea of multilayer encoding, "
         "\nto ensure your private information and "
         "\n4search history can't be read by anyone except you.\n\n";
    return 4;
}

int privacyPolicy() {
    AuthManager &authManager = AuthManager::getInstance();
    auto temp = authManager.getCurrentUser();
    cout << temp->getId();

    cout <<
         "Privacy policy is for telling you about basic rules and agreements between me and you."
         "\n we'll get to this in a bit. \n\n";
    return 5;
}

#pragma endregion

void authorizeUser(User user) {
    AuthManager &authManager = AuthManager::getInstance();
    if (authManager.login(user.getUsername(), user.getPassword(), user.getAuthority())) {
        std::shared_ptr<User> user = authManager.getCurrentUser();
        std::cout << "User " << user->getUsername() << " has logged in with ID " << user->getId() << std::endl;
    } else {
        std::cerr << "Login failed for user " << user.getUsername() << std::endl;
    }
}

void logoutUser() {
    AuthManager &authManager = AuthManager::getInstance();
    authManager.logout();
    std::cout << "User has logged out." << std::endl;
}


const int ITEMS_NUMBER = 6;
string username, password;


int main() {

    std::shared_ptr<User> user = AuthManager::getInstance().getCurrentUser();
    if (user) {
        std::cout << "Current User: " << user->getUsername() << ", ID: " << user->getId() << std::endl;
    }

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




