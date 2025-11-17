#include "Engine.h"
#include "utils/Logger.h"
#include <SDL3/SDL.h>

Engine* Engine::s_instance = nullptr;

void Engine::Initialize() {
    Logger::Log("Initializing Engine");

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        Logger::Err(std::string("SDL_Init failed: ") + SDL_GetError());
        return;
    }

    Window mainWindow = Window();
    windows.push_back(mainWindow);

    Run();
}

void Engine::Run() {
    Logger::Log("Running Engine");

    bool running = true;
    while (running) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        Update();
    }

    SDL_Quit();
}

void Engine::Update() {
    Logger::Log("Updating Engine");
}