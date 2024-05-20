#pragma once

#include "../command/ExpenseCommand.hpp"

class ExpenseManager{
    public:
        void executeCommand(Command* command);
};