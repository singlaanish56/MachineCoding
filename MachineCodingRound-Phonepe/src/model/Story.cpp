
#include "../../includes/model/Story.hpp"

Story::Story(int id, int parentId) : id(id), parentId(parentId) {}

void Story::add(Component* component) {
    tasks.push_back(component);
}

void Story::remove(Component* component) {

}

void Story::display() const {
    for (auto task : tasks) {
        task->display();
    }
}

int Story::getId() const {
    return id;
}

int Story::getParentId() const {
    return parentId;
}

void Story::addChildren(Component* component)
{
    tasks.push_back(component);
}