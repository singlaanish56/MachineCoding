#include "../../includes/managers/StoryManager.hpp"
#include <iostream>

StoryManager::StoryManager() {}

StoryManager& StoryManager::getInstance() {
    static StoryManager instance;
    return instance;
}

Story* StoryManager::createComponent(const std::string& description, const std::string& deadline, const User& assignedUser, Component* parent) {

    if(parent)
    {
        int parentId = parent->getId();
        Story* story = new Story(stories.size() + 1, parentId);
        stories.insert({story->getId(),story});
        parent->addChildren(story);
        return story;
    }else{
        return nullptr;
    }

}

Story* StoryManager::getComponentById(int id) {
    auto it = stories.find(id);
    if (it != stories.end()) {
        return it->second;
    }
    return nullptr;
}

void StoryManager::updateComponent(int id, const std::string& description, const std::string& deadline, Component::Status status) {
    // could be implemented
}

void StoryManager::deleteComponent(int id) {
    auto it = stories.find(id);
    if (it != stories.end()) {
        delete it->second;
        stories.erase(it);
    } else {
        std::cout << "Story with ID " << id << " not found." << std::endl;
    }
}
