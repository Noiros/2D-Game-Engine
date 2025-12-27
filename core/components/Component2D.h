#pragma once
#include "Component.h"
#include "SDL3/SDL_render.h"

class Component2D : public Component {
public:
    void ValidateComponent() override {
        SceneTree::Get().component2DList.push_back(this);
        Component::ValidateComponent();
    }
    virtual void Render(SDL_Renderer* renderer) {}
};
