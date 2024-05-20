#pragma once

#include <string>
#include <unordered_map>

class User{
private:
    std::string _userId;
    std::string _userName;
    std::string _email;
    std::string _mobileNumber;
    std::unordered_map<std::string, double> _updateBalances;
    std::unordered_map<std::string, std::unordered_map<std::string, double>> _groupBalances;

public:
    User(std::string id, std::string name, std::string email, std::string mobile);

    //getters
    std::string getId();
    
    double getDirectBalanceByUser(const std::string& userid);
    double getBalanceByGroupAndUser(const std::string& groupId, const std::string& userid);

    void getAllDirectBalances();
    void getAllGroupBalances();

    void getAllBalances();

    //setters
    void updateDirectBalances(const std::string& userid, double amount);
    void updateGroupBalance(const std::string& groupId,const std::string& userid, double amount);
};