#include "Window.h"

Window::Window() {
    window = SDL_CreateWindow("Main", 1280, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    if (!window) {
        return;
    }
    renderer = SDL_CreateRenderer(window, NULL);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    gl_context = SDL_GL_CreateContext(window);
    if (!gl_context) {
        return;
    }

    if (!SDL_GL_MakeCurrent(window, gl_context)) {
        return;
    }
}
