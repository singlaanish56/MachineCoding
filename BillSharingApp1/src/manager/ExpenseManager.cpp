#include "../../includes/manager/ExpenseManager.hpp"


ExpenseManager::ExpenseManager(){}

void ExpenseManager::executeCommand(Command* command)
{
    command->execute();
}