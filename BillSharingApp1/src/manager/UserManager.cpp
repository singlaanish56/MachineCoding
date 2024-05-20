#include "../../includes/manager/UserManager.hpp"

#include <bits/stdc++.h>

UserManager::UserManager() {}

UserManager& UserManager::getInstance()
{
 static UserManager instance;
 return instance;
}

void UserManager::addUser(const std::string& name,const std::string& email,const std::string& mobile )
{
    //validate the input here

    // generate the id
    std::string id = "user"+name+to_string(idCounter++);

    User* user = new User(id, name, email, mobile);

    usersMap[id]  = user;
 
}

void UserManager::removeUser(const std::string& userId)
{
    //TODO
}

User* UserManager::getUserById(const std::string& id)
{
    if(usersMap.find(id)==usersMap.end());
        return null;

    return usersMap[id];
}