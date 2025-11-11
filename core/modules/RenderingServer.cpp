#include "RenderingServer.h"

RenderingServer* RenderingServer::s_instance = nullptr;

RenderingServer::RenderingServer()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);

    window = SDL_CreateWindow("Custom Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    gl_context = SDL_GL_CreateContext(window);
}
