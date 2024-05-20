#include "../../includes/managers/SubTaskManager.hpp"
#include "iostream"

SubTaskManager::SubTaskManager() {}

SubTaskManager& SubTaskManager::getInstance() {
    static SubTaskManager instance;
    return instance;
}

Task* SubTaskManager::createComponent(const std::string& description, const std::string& deadline, const User& assignedUser, Component* parent) {
   if(parent)
    {
        int parentId = parent->getId();
        Task* task = new Task(subtasks.size() + 1,description,deadline,assignedUser, parentId);
        subtasks.insert({task->getId(),task});
        parent->addChildren(task);
        return task;
    }else{
        return nullptr;
    }
}

Task* SubTaskManager::getComponentById(int id) {

    auto it = subtasks.find(id);
    if (it != subtasks.end()) {
            return it->second;
    }

    return nullptr;
}

void SubTaskManager::updateComponent(int id, const std::string& description, const std::string& deadline, Component::Status status) {
    Task* task = getComponentById(id);
    if (task) {
        task->updateTask(description, deadline, status);
    } else {
        std::cout << "Task" << " with ID " << id << " not found." << std::endl;
    }
}

void SubTaskManager::deleteComponent(int id) {
    auto it = subtasks.find(id);
    if (it != subtasks.end()) {
        delete it->second;
        subtasks.erase(it);
    } else {
        std::cout << "Task with ID " << id << " not found." << std::endl;
    }
}
