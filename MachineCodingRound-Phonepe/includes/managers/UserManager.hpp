#pragma once


#include "../model/User.hpp"
#include <string>
#include <map>


class UserManager {
public:
    static UserManager& getInstance();
    void addUser(const std::string& username, const std::string& password);
    bool authenticate(const std::string& username, const std::string& password) const;
    User* getUser(const std::string& username);

private:
    UserManager() ; 
    std::map<std::string, std::pair<User*,std::string>> users; 

};

