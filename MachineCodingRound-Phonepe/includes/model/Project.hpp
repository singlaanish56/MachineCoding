#pragma once

#include <vector>
#include "Component.hpp"

class Project : public Component {
public:
    Project(int id);
    void add(Component* component) override;
    void remove(Component* component) override;
    void display() const override;
    int getId() const override;
    void addChildren(Component* component) override;

private:
    int id;
    std::vector<Component*> stories;
};

