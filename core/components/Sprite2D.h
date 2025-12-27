#pragma once

#include <SDL3/SDL_render.h>

#include "Component2D.h"
#include "Transform2D.h"

class Sprite2D : public Component2D
{
public:
    void Ready();
    void Render(SDL_Renderer* renderer);
    void Update(float delta);

private:
    Transform2D* transform;
};
