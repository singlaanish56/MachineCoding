#pragma once

#include "User.hpp"
#include "string"
#include "SplitType.hpp"
#include <vector>

class Expense{
    private:

        User* _paidBy;
        double _amount;
        std::vector<User*> _participants;
        SplitType _splitType;
        std::vector<double> _splits;

    public:

    Expense(double amount, User* paidBy, std::vector<User*> participants, SplitType split, std::vector<double> _splits);

};