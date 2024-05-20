#include "../../includes/model/Task.hpp"
#include <iostream>

Task::Task(int id, const std::string& description, const std::string& deadline, const User& assignedUser, int parentId)
    : id(id), description(description), deadline(deadline), assignedUser(assignedUser), status(Status::TO_DO), parentId(parentId) {}

void Task::updateTask(const std::string& description, const std::string& deadline, Status status) {
    this->description = description;
    this->deadline = deadline;
    this->status = status;
}

void Task::assignUser(const User& user) {
    assignedUser = user;
}

void Task::deleteTask() {
 
}

std::string Task::getDescription() const {
    return description;
}

std::string Task::getDeadline() const {
    return deadline;
}

User Task::getAssignedUser() const {
    return assignedUser;
}

Task::Status Task::getStatus() const {
    return status;
}

int Task::getId() const {
    return id;
}

int Task::getParentId() const {
    return parentId;
}


void Task::add(Component* subtask) {
    subtasks.push_back(subtask);
}

void Task::remove(Component* subtask) {
    //remove subtask;
}

const std::vector<Component*>& Task::getSubtasks() const {
    return subtasks;
}

void Task::display() const {
    std::cout << "ID: " << getId() << ", Description: " << description << ", Deadline: " << deadline << ", Status: ";
    switch (status) {
        case Status::TO_DO:
            std::cout << "To Do";
            break;
        case Status::PENDING:
            std::cout << "Pending";
            break;
        case Status::DONE:
            std::cout << "Done";
            break;
    }
    std::cout << "\n";

    if (!subtasks.empty()) {
        std::cout << "Subtasks:\n";
        for (auto subtask : subtasks) {
            subtask->display();
        }
        std::cout<<std::endl;
    }
}

void Task::addChildren(Component* component)
{
    subtasks.push_back(component);
}