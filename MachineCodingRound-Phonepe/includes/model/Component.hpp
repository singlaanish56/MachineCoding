#pragma once

class Component {
public:
    enum class Status { TO_DO, PENDING, DONE };
    virtual int getId() const =0;
    virtual void add(Component* component) = 0;
    virtual void remove(Component* component) = 0;
    virtual void display() const = 0;
    virtual void addChildren(Component* component) = 0;
};

