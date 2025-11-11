#include "Engine.h"
#include "Logger.h"

#include <Windows.h>

#ifdef EDITOR
#include "../editor/Editor.h"
#endif

Engine* Engine::s_instance = nullptr;

Engine::Engine()
{
    Logger::Log("Engine constructor called");
}

Engine::~Engine()
{
    Logger::Log("Engine destructor called");
    s_instance = nullptr;
}


void Engine::Setup()
{
    SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL);
    
    SceneTree::SetInstance(&sceneTree);
    InputManager::SetInstance(&inputManager);
    ResourcesManager::SetInstance(&resourcesManager);
    RenderingServer::SetInstance(&renderingServer);
    RenderingServer3D::SetInstance(&renderingServer3D);
    RenderingServer2D::SetInstance(&renderingServer2D);
    PhysicsServer2D::SetInstance(&physicsServer2D);

    isRunning = true;
    Logger::Log("Engine setup done !");
}

void Engine::Run()
{
    while (isRunning)
    {
        Update();
    }
}

void Engine::Quit()
{
    
}

void Engine::Update()
{
    inputManager.ProcessInput();

    float deltaTime = (SDL_GetTicks64() - millisecondPreviousFrame) / 1000.0f;
    millisecondPreviousFrame = SDL_GetTicks64();

    //renderingServer2D.Clear();

    uint64_t startUpdateMillis = SDL_GetTicks64();
    sceneTree.Update(deltaTime);
    millisUpdateFrame = SDL_GetTicks64() - startUpdateMillis;

    uint64_t startRenderMillis = SDL_GetTicks64();

    //renderingServer3D.Render();
    //renderingServer2D.Render();
    
    millisRenderFrame = SDL_GetTicks64() - startRenderMillis;

    millisFrame = SDL_GetTicks64() - millisecondPreviousFrame;
}
