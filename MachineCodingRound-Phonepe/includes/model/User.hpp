#pragma once

#include <string>

class User {
public:
    User(const std::string& username, const std::string& password);
    std::string getUsername() const;
    friend class UserManager; // Allow UserManager to access private members

private:
    std::string username;
    std::string password;
};

