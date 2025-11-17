#pragma once

#include <SDL3/SDL_render.h>

#include "RenderingServer.h"

class RenderingServer2D
{
public:
    RenderingServer2D() = default;
    ~RenderingServer2D() = default;
    
    // Setup Singleton
    static void SetInstance(RenderingServer2D* instance) { s_instance = instance; }
    static RenderingServer2D& Get() { return *s_instance; }
    RenderingServer2D(const RenderingServer2D&) = delete;
    RenderingServer2D& operator=(const RenderingServer2D&) = delete;

private:
    static RenderingServer2D* s_instance;

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
};
