#pragma once

#include "../model/Group.hpp"
#include <string>
#include <map>
#include <vector>

class GroupManager{
private:
    GroupManager();

    std::map<std::string, Group*> groupsMap;
    int idCounter=0;

public:
    static GroupManager& getInstance();
    void createGroup(const std::string& name, const std::vector<User*>& users);
    void deleteGroup(const std::string& groupId);

    //getters
    Group* getGroup(const std::string& groupId);

};