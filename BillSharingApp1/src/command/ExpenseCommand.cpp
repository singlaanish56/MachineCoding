#include "../../includes/command/ExpenseCommand.hpp"
#include "../../includes/model/Expense.hpp"
#include "../../includes/strategy/SplitStrategy.hpp"

namespace{
    SplitStrategy* getSplitStrategy(SplitType type)
    {
        if(type==SplitType::EQUAL)
        {
            return new EqualSplitStrategy();
        }else if(type == SplitType::EXACT)
        {
            return new ExactSplitStrategy();
        }else if(type == SplitType::PERCENTAGE)
        {
            return new PercentageSplitStrategy();
        }else{
            return NULL;
        }
    }
}
AddExpenseDirectly::AddExpenseDirectly(        ExpenseManager* expenseManager,
        double amount,
        User* paidBy,
        std::vector<User*> participants,
        SplitType splitType,
        std::vector<double> splits):
_expenseManager(expenseManager), _amount(amount), _paidBy(paidBy), _participants(participants), _splitType(splitType), _splits(splits)
{
}

void AddExpenseDirectly::execute()
{   
    SplitStrategy* split =getSplitStrategy(_splitType);

    std::vector<double> shares = split->split(_amount, _participants, _splits);
    Expense* expense = new Expense(_amount, _paidBy,_participants, _splitType, shares );

    for(int i=0;i<_participants.size();i++)
    {
        _paidBy->updateDirectBalances(_participants[i]->getId(),shares[i]);
    }
}

AddExpenseToGroup::AddExpenseToGroup(       ExpenseManager* expenseManager,
        double amount,
        User* paidBy,
        std::vector<User*> participants,
        SplitType splitType,
        std::vector<double> splits,
        Group* groupId):
_expenseManager(expenseManager), _amount(amount), _paidBy(paidBy), _participants(participants), _splitType(splitType), _splits(splits),_groupId(groupId)
{
}

void AddExpenseToGroup::execute()
{
    SplitStrategy* split =getSplitStrategy(_splitType);

    std::vector<double> shares = split->split(_amount, _participants, _splits);
    Expense* expense = new Expense(_amount, _paidBy,_participants, _splitType, shares );

    for(int i=0;i<_participants.size();i++)
    {
        _paidBy->updateGroupBalance(_groupId->getGroupId(), _participants[i]->getId(),shares[i]);
    }
}