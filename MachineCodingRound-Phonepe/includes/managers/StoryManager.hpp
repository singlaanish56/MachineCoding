#pragma once

#include "ComponentManager.hpp"
#include <unordered_map>
#include "../model/Story.hpp"

class StoryManager : public ComponentManager {
public:
    static StoryManager& getInstance();
    Story* createComponent(const std::string& description, const std::string& deadline, const User& assignedUser, Component* parent) override;
    Story* getComponentById(int id) override;
    void updateComponent(int id, const std::string& description, const std::string& deadline, Component::Status status) override;
    void deleteComponent(int id) override;

private:
    StoryManager();
    StoryManager(const StoryManager&) = delete;
    StoryManager& operator=(const StoryManager&) = delete;

    std::unordered_map<int, Story*> stories;
};

