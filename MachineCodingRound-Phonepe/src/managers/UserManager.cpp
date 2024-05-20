#include "../../includes/managers/UserManager.hpp"

UserManager::UserManager() {}

UserManager& UserManager::getInstance() {

    static UserManager instance;
    return instance;
}

void UserManager::addUser(const std::string& username, const std::string& password) {

    users.emplace(username, make_pair(new User(username, password), password));
}

bool UserManager::authenticate(const std::string& username, const std::string& password) const {
    auto it = users.find(username);
    if (it != users.end()) {
        return it->second.second == password;
    }
    return false;
}

User* UserManager::getUser(const std::string& username) {
    auto it = users.find(username);
    if (it != users.end()) {
        return (it->second.first);
    }
    return nullptr;
}
