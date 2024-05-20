#include "../../includes/managers/ProjectManager.hpp"
#include <iostream>

ProjectManager::ProjectManager() : taskManager(nullptr), subTaskManager(nullptr), storyManager(nullptr) {}

ProjectManager& ProjectManager::getInstance() {
    static ProjectManager instance;
    return instance;
}

Project* ProjectManager::createComponent(const std::string& description, const std::string& deadline, const User& assignedUser, Component* parent) {
    // Create new instances of TaskManager, SubtaskManager, and StoryManager
    taskManager = &TaskManager::getInstance();
    subTaskManager = &SubTaskManager::getInstance();
    storyManager = &StoryManager::getInstance();

    int id = projects.size()+1;
    Project* project = new Project(id);

    // Associate the managers with the project
    projects.insert({id,{project, this}});

    return project;
}

Project* ProjectManager::getComponentById(int id) {
    auto it = projects.find(id);
    if (it != projects.end()) {
        return it->second.first;
    }
    return nullptr;
}

void ProjectManager::updateComponent(int id, const std::string& description, const std::string& deadline, Component::Status status) {
    // to be implemented
}

void ProjectManager::deleteComponent(int id) {
    auto it = projects.find(id);
    if (it != projects.end()) {
        delete it->second.first;
         delete it->second.second;
        projects.erase(it);
    } else {
        std::cout << "Project with ID " << id << " not found." << std::endl;
    }
}

TaskManager* ProjectManager::getTaskManager(const int id) const {
    auto it = projects.find(id);
    if (it != projects.end()) {
        return it->second.second->taskManager;
    }
    return nullptr;
}

SubTaskManager* ProjectManager::getSubTaskManager(const int id) const {
    auto it = projects.find(id);
    if (it != projects.end()) {
        return it->second.second->subTaskManager;
    }
    return nullptr;
}

StoryManager* ProjectManager::getStoryManager(const int id) const {
    auto it = projects.find(id);
    if (it != projects.end()) {
        return it->second.second->storyManager;
    }
    return nullptr;
}
