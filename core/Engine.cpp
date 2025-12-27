#include "Engine.h"

#include <iostream>

#include "utils/Logger.h"
#include "GameObject.h"
#include <SDL3/SDL.h>

#include "EventType.h"
#include "modules/Event.h"

Engine* Engine::s_instance = nullptr;

void Engine::Initialize(MainApp* main_app) {
    Logger::Log("Initializing Engine");

    mainApp = main_app;

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        Logger::Err(std::string("SDL_Init failed: ") + SDL_GetError());
        return;
    }

    Logger::Log("Creating Window");
    Window mainWindow = Window();
    windows.push_back(mainWindow);

    Logger::Log("Initializing Scene Tree");
    SceneTree::SetInstance(&sceneTree);
    Logger::Log("Initializing Rendering Server 2D");
    RenderingServer2D::SetInstance(&rendering_server_2d);
    rendering_server_2d.Initialize();
    Logger::Log("Initializing Rendering Server 3D");
    RenderingServer3D::SetInstance(&rendering_server_3d);
    Logger::Log("Initializing Event");
    Event::SetInstance(&event);

    Run();
}

void Engine::Run() {
    Logger::Log("Running Engine");

    mainApp->Ready();

    bool running = true;
    while (running) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            Event::Get().Publish(InputEvent{ e });
            if (e.type == SDL_EVENT_QUIT) running = false;
        }

        MainLoop();
    }

    SDL_Quit();
}

void Engine::MainLoop() {
    mainApp->Update();

    for (GameObject* gameObject : sceneTree.gameObjectList) {
        gameObject->Update(0.0f);
    }

    for (Component* component : sceneTree.component2DList) {
        component->Update(0.0f);
    }

    //rendering_server_2d.Render();

}