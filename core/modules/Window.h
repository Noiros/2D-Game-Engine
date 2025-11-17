#pragma once
#include <SDL3/SDL.h>

class Window {
    public:
    Window();

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
};
