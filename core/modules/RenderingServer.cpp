#include "RenderingServer.h"

RenderingServer* RenderingServer::s_instance = nullptr;

RenderingServer::RenderingServer()
{
    SDL_Init(SDL_INIT_EVENTS);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);

    window = SDL_CreateWindow("Custom Game Engine", 1920, 1080, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, "test");
    gl_context = SDL_GL_CreateContext(window);
}
