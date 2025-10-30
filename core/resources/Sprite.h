#pragma once
#include "../Resource.h"
#include <SDL_render.h>
#include <string_view>
#include "../modules/ResourcesManager.h"

class Sprite : public Resource
{
public:
    Sprite(std::string_view textureName) : textureName(textureName)
    {
        texture = ResourcesManager::Get().GetTexture(textureName);
    }
    
    std::string_view textureName;
    SDL_Texture* texture;
};
