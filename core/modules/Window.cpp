#include "Window.h"

Window::Window() {
    window = SDL_CreateWindow("Game Engine", 1920, 1080,SDL_WINDOW_RESIZABLE);
}
