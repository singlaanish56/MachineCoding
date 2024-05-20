#pragma once

#include <string>
#include <vector>
#include "Component.hpp"
#include "User.hpp"

class Task : public Component {
public:

    Task(int id, const std::string& description, const std::string& deadline, const User& assignedUser, int parentId = -1);
    void updateTask(const std::string& description, const std::string& deadline, Status status);
    void assignUser(const User& user);
    void deleteTask();
    std::string getDescription() const;
    std::string getDeadline() const;
    User getAssignedUser() const;
    Status getStatus() const;
    int getId() const;
    int getParentId() const;
    void display() const override;

    void add(Component* component) override;
    void remove(Component* component) override;
    void addChildren(Component* component) override;
    const std::vector<Component*>& getSubtasks() const;

private:
    int id;
    int parentId;
    std::string description;
    std::string deadline;
    User assignedUser;
    Status status;
    std::vector<Component*> subtasks;
};
