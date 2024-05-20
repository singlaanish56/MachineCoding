#pragma once

#include "../model/User.hpp"
#include <string>
#include <map>

class UserManager{
private:
    UserManager();

    std::map<std::string, User*> usersMap;
    int idCounter=0;

public:
    static UserManager& getInstance();
    void addUser(const std::string& name,const std::string& email,const std::string& mobile );
    void removeUser(const std::string& userId);

    //getters
    User* getUserById(const std::string& userId);

};