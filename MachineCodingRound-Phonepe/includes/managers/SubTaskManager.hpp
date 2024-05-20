#pragma once

#include "ComponentManager.hpp"
#include <unordered_map>
#include "../model/Task.hpp"

class SubTaskManager : public ComponentManager {
public:
    static SubTaskManager& getInstance();
    Task* createComponent(const std::string& description, const std::string& deadline, const User& assignedUser, Component* parent) override;
    Task* getComponentById(int id) override;
    void updateComponent(int id, const std::string& description, const std::string& deadline, Component::Status status) override;
    void deleteComponent(int id) override;

private:
    SubTaskManager();
    SubTaskManager(const SubTaskManager&) = delete;
    SubTaskManager& operator=(const SubTaskManager&) = delete;

    std::unordered_map<int, Task*> subtasks;
};

