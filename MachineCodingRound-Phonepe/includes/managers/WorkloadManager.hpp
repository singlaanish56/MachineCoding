#pragma once

#include "UserManager.hpp"
#include "../model/User.hpp"
#include "../model/Task.hpp"
#include <unordered_map>
#include <vector>
#include <utility>

class WorkloadManager {
public:
    static WorkloadManager& getInstance();
    void trackTask(const User& user, const Task& task);
    void getWorkload(const User& user) const;

private:
    WorkloadManager(); // Private constructor for Singleton
    std::unordered_map<std::string, std::pair<int,std::vector<Task>>> userWorkloadMap;
};

