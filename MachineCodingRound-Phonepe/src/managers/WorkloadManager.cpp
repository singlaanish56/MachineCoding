#include "../../includes/managers/WorkloadManager.hpp"
#include <iostream>

WorkloadManager::WorkloadManager() {}
WorkloadManager& WorkloadManager::getInstance() {
    static WorkloadManager instance;
    return instance;
}

void WorkloadManager::trackTask(const User& user, const Task& task) {
    // Increment workload for the user
    std::string username = user.getUsername();
    if(userWorkloadMap.find(username)==userWorkloadMap.end())
    {
        userWorkloadMap.insert({username, {0,{}}});
    }
    userWorkloadMap[username].first++;
    userWorkloadMap[username].second.push_back(task);
}

void WorkloadManager::getWorkload(const User& user) const {

    std::string username = user.getUsername();
    auto it = userWorkloadMap.find(username);
    if (it != userWorkloadMap.end()) {
        auto vec = userWorkloadMap.at(username).second;
        for(auto task : vec)
        {
            task.display();
        }        
    } else {
        std::cout<<"No task found for the user"<<std::endl;
    }
}
