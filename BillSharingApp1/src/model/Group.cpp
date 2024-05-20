#include "../../includes/model/Group.hpp"

Group::Group(std::string id, std::string name, std::vector<User*> users): _groupId(id), _groupName(name), _users(users)
{
}

std::string Group::getGroupId()
{
    return _groupId;
}