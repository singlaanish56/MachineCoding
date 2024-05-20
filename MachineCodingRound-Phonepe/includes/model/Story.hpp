#pragma once

#include <vector>
#include "Component.hpp"

class Story : public Component {
public:
    Story(int id, int parentId = -1);
    void add(Component* component) override;
    void remove(Component* component) override;
    void display() const override;
    int getId() const;
    int getParentId() const;
    void addChildren(Component* component) override;
    
private:
    int id;
    int parentId;
    std::vector<Component*> tasks;
};

