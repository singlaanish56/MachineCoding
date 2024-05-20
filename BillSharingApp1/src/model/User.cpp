#include "../../includes/model/User.hpp"
#include <iostream>
#include <bits/stdc++.h>

User::User(std::string id, std::string name, std::string email, std::string mobile): _userId(id), _userName(name), _email(email), _mobileNumber(mobile)
{
}

std::string getId()
{
    return _userId;
}

double  User::getDirectBalanceByUser(const std::string& userid)
{
    if(_updateBalances.find(userid)==_updateBalances.end())
        return 0;

    return _updateBalances[userid];
}

double  User::getBalanceByGroupAndUser(const std::string& groupId, const std::string& userid)
{
    if(_groupBalances.find(groupId)==_groupBalances.end())
        return 0;
    if(_groupBalances[groupId].find(userid)==_groupBalances[groupId].end())
        return 0;

    return _groupBalances[groupId][userid];
}

void User::updateDirectBalances(const std::string& userid, double amount)
{
    _updateBalances[userid]+=amount;
}

void User::updateGroupBalance(const std::string& groupId,const std::string& userid, double amount)
{
    _groupBalances[groupId][userid]+=amount;
}


void User::getAllDirectBalances()
{
    for(auto it : _updateBalances)
    {
        std::cout<<it.first<<" owes "<<_userId<<" "<<to_string(it.second)<<std::endl;
    }
}

void User::getAllGroupBalances()
{
    for(auto it : _groupBalances)
    {
        std::cout<<"Group "<<it.first<<std::endl;
        for(auto it2 : it.second)
        {
           std::cout<<it2.first<<" owes "<<_userId<<" "<<to_string(it2.second)<<std::endl; 
        }
    }
}

void getAllBalances()
{
    getAllDirectBalances();
    getAllGroupBalances();
}
