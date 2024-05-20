#pragma once

#include <vector>
#include "../model/User.hpp"

class SplitStrategy{
public:
    virtual std::vector<double> split(double amount, std::vector<User*> participants, std::vector<double> splits) =0 ;
};

class EqualSplitStrategy : public SplitStrategy{
public:
    std::vector<double> split(double amount, std::vector<User*> participants, std::vector<double> splits);
};

class ExactSplitStrategy : public SplitStrategy{
public:
    std::vector<double> split(double amount, std::vector<User*> participants, std::vector<double> splits);
};

class PercentageSplitStrategy : public SplitStrategy{
public:
    std::vector<double> split(double amount, std::vector<User*> participants, std::vector<double> splits) override;
};