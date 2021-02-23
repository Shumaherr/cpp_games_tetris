//
// Created by Aleksandr on 14.02.2021.
//

#include <set>
#include <algorithm>
#include "GameObject.h"

void GameObject::AddComponent(Component* component) {
    components.insert(component);
}

void GameObject::RemoveComponent(Component *component) {
    components.erase(component);
}

void GameObject::Update(float deltaTime) {
    for(auto component : components)
    {
        component->Update(deltaTime);
    }

}

std::unordered_set<Component *> GameObject::GetComponents() {
    return components;
}

Component* GameObject::GetComponent(Component* component) {
    auto iter = std::find(components.begin(), components.end(), component);
    return iter.operator*();
}
