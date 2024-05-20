#pragma once

#include "../model/Component.hpp"
#include "../model/User.hpp"
#include<string>

class ComponentManager {
public:

    virtual Component* createComponent(const std::string& description, const std::string& deadline, const User& assignedUser, Component* Parent) = 0;
    virtual Component* getComponentById(int id) = 0;
    virtual void updateComponent(int id, const std::string& description, const std::string& deadline, Component::Status status) = 0;
    virtual void deleteComponent(int id) = 0;
};

