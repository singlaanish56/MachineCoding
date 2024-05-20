#pragma once

#include <string>
#include <vector>
#include "User.hpp"

class Group{
private:
    std::string _groupId;
    std::string _groupName;
    std::vector<User*> _users;

public:
    Group(std::string id, std::string name, std::vector<User*> users);

    //getters
    std::string getGroupId();
    //setters
};