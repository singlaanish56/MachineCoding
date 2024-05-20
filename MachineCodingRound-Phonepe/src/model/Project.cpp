#include "../../includes/model/Project.hpp"

Project::Project(int id) : id(id) {}

void Project::add(Component* component) {
    stories.push_back(component);
}

void Project::remove(Component* component) {

}

void Project::display() const {

    for (auto story : stories) {
        story->display();
    }
}

int Project::getId() const {
    return id;
}

void Project::addChildren(Component* component)
{
    stories.push_back(component);
}