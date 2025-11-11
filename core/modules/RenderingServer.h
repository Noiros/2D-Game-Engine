#pragma once
#include <SDL.h>

class RenderingServer
{
public:
    RenderingServer();
    ~RenderingServer() {};
    
    // Setup Singleton
    static void SetInstance(RenderingServer* instance) { s_instance = instance; }
    static RenderingServer& Get() { return *s_instance; }
    RenderingServer(const RenderingServer&) = delete;
    RenderingServer& operator=(const RenderingServer&) = delete;

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_GLContext gl_context;

private:
    static RenderingServer* s_instance;

};
