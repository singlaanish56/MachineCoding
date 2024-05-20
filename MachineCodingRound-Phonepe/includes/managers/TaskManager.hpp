#pragma once

#include "ComponentManager.hpp"
#include <unordered_map>
#include "../model/Task.hpp"


class TaskManager : public ComponentManager {
public:
    static TaskManager& getInstance();
    Task* createComponent(const std::string& description, const std::string& deadline, const User& assignedUser, Component* parent) override;
    Task* getComponentById(int id) override;
    void updateComponent(int id, const std::string& description, const std::string& deadline, Component::Status status) override;
    void deleteComponent(int id) override;

private:
    TaskManager();
    TaskManager(const TaskManager&) = delete;
    TaskManager& operator=(const TaskManager&) = delete;

    std::unordered_map<int, Task*> tasks;
};

