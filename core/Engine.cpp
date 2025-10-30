#include "Engine.h"
#include "Logger.h"

#include <Windows.h>

#include "modules/RenderingServerUI.h"

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
    RenderingServer2D::SetInstance(&renderingServer2D);
    RenderingServerUI::SetInstance(&renderingServerUI);
    PhysicsServer2D::SetInstance(&physicsServer2D);

    renderingServerUI.Initialize(renderingServer2D.window, renderingServer2D.renderer);
    
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
#ifdef EDITOR
    Editor::Get().ShutdownEditorResources();
    renderingServerUI.Shutdown();
#endif

    SDL_DestroyRenderer(renderingServer2D.renderer);
    SDL_DestroyWindow(renderingServer2D.window);
    SDL_Quit();
    Logger::Log("SDL closed !");
}

void Engine::Update()
{
#ifdef CAP_FPS
    uint64_t timeToWait = MILLISEC_PER_FRAME - (SDL_GetTicks64() - millisecondPreviousFrame);
    if (timeToWait > 0 && timeToWait <= MILLISEC_PER_FRAME)
        SDL_Delay(timeToWait); //yield to other processes
#endif // CAP_FPS

    SDL_Event sdlEvent;
    while (SDL_PollEvent(&sdlEvent))
    {
        renderingServerUI.ProcessEvent(sdlEvent);
        switch (sdlEvent.type)
        {
        case SDL_QUIT: isRunning = false;
            break;
        case SDL_KEYDOWN: if (sdlEvent.key.keysym.sym == SDLK_ESCAPE) isRunning = false;
            break;
        }
    }

    inputManager.ProcessInput();

    float deltaTime = (SDL_GetTicks64() - millisecondPreviousFrame) / 1000.0f;
    millisecondPreviousFrame = SDL_GetTicks64();

    renderingServer2D.Clear();

    uint64_t startUpdateMillis = SDL_GetTicks64();
    sceneTree.Update(deltaTime);
    millisUpdateFrame = SDL_GetTicks64() - startUpdateMillis;

    uint64_t startRenderMillis = SDL_GetTicks64();
    
    renderingServer2D.Render();
    renderingServerUI.Render();
    
    millisRenderFrame = SDL_GetTicks64() - startRenderMillis;

    millisFrame = SDL_GetTicks64() - millisecondPreviousFrame;
}
