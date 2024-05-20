

#include "ComponentManager.hpp"
#include <unordered_map>
#include "../model/Project.hpp"
#include "TaskManager.hpp"
#include "StoryManager.hpp"
#include "SubTaskManager.hpp"

class ProjectManager : public ComponentManager {
public:
    static ProjectManager& getInstance();
    Project* createComponent(const std::string& description, const std::string& deadline, const User& assignedUser, Component* Parent = nullptr) override;

    Project* getComponentById(int id) override;
    void updateComponent(int id, const std::string& description, const std::string& deadline, Component::Status status) override;
    void deleteComponent(int id) override;

    TaskManager* getTaskManager(const int id) const;
    SubTaskManager* getSubTaskManager(const int id) const;
    StoryManager* getStoryManager(const int id) const;

private:
    ProjectManager();
    ProjectManager(const ProjectManager&) = delete;
    ProjectManager& operator=(const ProjectManager&) = delete;

    TaskManager* taskManager;
    SubTaskManager* subTaskManager;
    StoryManager* storyManager;

    std::unordered_map<int, std::pair<Project*,ProjectManager*>> projects;
};

