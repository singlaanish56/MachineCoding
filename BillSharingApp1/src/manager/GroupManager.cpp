#include "../../includes/manager/GroupManager.hpp"

#include <bits/stdc++.h>

GroupManager::GroupManager() {}

void GroupManager::createGroup(const std::string& name,std::vector<User*>& users )
{
    //validate the input here

    // generate the id
    // id generation can be improved with
    std::string id = "group"+name+to_string(idCounter++);

    Group* group = new Group(id, name, users);

    groupsMap[id]  = group;
 
}

void GroupManager::deleteGroup(const std::string& groupId)
{
    //TODO
}

Group* GroupManager::getGroup(const std::string& id)
{
    if(groupsMap.find(id)==groupsMap.end());
        return null;

    return groupsMap[id];
}