//
// Created by Aleksandr on 14.02.2021.
//

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
