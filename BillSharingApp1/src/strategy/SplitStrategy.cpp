#include "../../includes/strategy/SplitStrategy.hpp"

std::vector<double> EqualSplitStrategy::split(double amount, std::vector<User*> participants, std::vector<double> splits)
{   
    int users= participants.size();
    double share = round(amount/users * 100) / 100;
    double totalShare = share * users;
    double secondShare = share;

    if(totalShare < amount)
    {
        secondShare -= 0.01;
    }

    std::vector<double> splits(users, share);
    splits[0]=secondShare;

    return splits;
}

std::vector<double> ExactSplitStrategy::split(double amount, std::vector<User*> participants, std::vector<double> splits)
{
    // not needed the exact split are provided with the user;
}

std::vector<double> PercentageSplitStrategy::split(double amount, std::vector<User*> participants, std::vector<double> splits)
{
    int users = participants.size();
    std::vector<double> shares;
    double totalShare = 0.0;

    for(double split : splits)
    {
        double share = round(amount * split/100 * 100) / 100;
        shares.push_back(share);

        totalShare += share;
    }

    if(totalShare < amount)
    {
        shares[0]+=0.01;
    }
}