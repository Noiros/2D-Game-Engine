#pragma once

#include <SDL3/SDL_render.h>

#include "Component2D.h"
#include "Transform2D.h"

class Sprite2D : public Component2D
{
public:
    Sprite2D() = default;

    bool HFlip = false;
    bool VFlip = false;

    void Ready();
    void Render();
    void Update(float delta);

private:
    Transform2D* transform;
};
