//
// Created by Aleksandr on 14.02.2021.
//
#pragma once
#include <unordered_set>
#include "Component.h"

class GameObject {

public:
    void AddComponent(Component* component);
    Component* GetComponent(Component* component);
    void RemoveComponent(Component* component);
    void Update(float deltaTime);
    std::unordered_set<Component*> GetComponents();
private:
    std::unordered_set<Component*> components;
};

