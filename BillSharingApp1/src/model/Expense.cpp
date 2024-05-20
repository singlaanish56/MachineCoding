#include "../../includes/model/Expense.hpp"

Expense::Expense(double amount, User* paidBy, std::vector<User*> participants, SplitType split,std::vector<double> splits)
: _paidBy(paidBy), _amount(amount), _participants(participants), _splitType(split), _splits(splits)
{
}
