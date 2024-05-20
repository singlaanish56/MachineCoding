#include "../../includes/managers/TaskManager.hpp"
#include "iostream"

TaskManager::TaskManager() {}

TaskManager& TaskManager::getInstance() {
    static TaskManager instance;
    return instance;
}

Task* TaskManager::createComponent(const std::string& description, const std::string& deadline, const User& assignedUser, Component* parent) {
   if(parent)
    {
        int parentId = parent->getId();
        Task* task = new Task(tasks.size() + 1,description,deadline,assignedUser, parentId);
        tasks.insert({task->getId(),task});
        parent->addChildren(task);
        return task;
    }else{
        return nullptr;
    }
}

Task* TaskManager::getComponentById(int id) {

    auto it = tasks.find(id);
    if (it != tasks.end()) {
            return it->second;
    }

    return nullptr;
}

void TaskManager::updateComponent(int id, const std::string& description, const std::string& deadline, Component::Status status) {
    Task* task = getComponentById(id);
    if (task) {
        task->updateTask(description, deadline, status);
    } else {
        std::cout << "Task" << " with ID " << id << " not found." << std::endl;
    }
}

void TaskManager::deleteComponent(int id) {
    auto it = tasks.find(id);
    if (it != tasks.end()) {
        delete it->second;
        tasks.erase(it);
    } else {
        std::cout << "Task with ID " << id << " not found." << std::endl;
    }
}
