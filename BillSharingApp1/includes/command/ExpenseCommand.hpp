#pragma once

#include "../manager/ExpenseManager.hpp"
#include "../model/User.hpp"
#include "../model/SplitType.hpp"
#include "../model/Group.hpp"
#include <vector>

class Command {
    public:
        virtual void execute() = 0;
};

class AddExpenseDirectly : public Command{
    private:
        ExpenseManager* _expenseManager;
        double _amount;
        User* _paidBy;
        std::vector<User*> _participants;
        SplitType _splitType;
        std::vector<double> _splits;

    public:
        AddExpenseDirectly(        ExpenseManager* expenseManager,
        double amount,
        User* paidBy,
        std::vector<User*> participants,
        SplitType splitType,
        std::vector<double> splits);

        void execute() override;
};

class AddExpenseToGroup : public Command{
    private:
       
        ExpenseManager* _expenseManager;
        double _amount;
        User* _paidBy;
        std::vector<User*> _participants;
        SplitType _splitType;
        std::vector<double> _splits;
         Group* _groupId;

    public:
        AddExpenseToGroup(        ExpenseManager* expenseManager,
        double amount,
        User* paidBy,
        std::vector<User*> participants,
        SplitType splitType,
        std::vector<double> splits,
        Group* groupId);
        
        void execute() override;
};