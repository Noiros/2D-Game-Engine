#include "Engine.h"
#include "Logger.h"

#include <Windows.h>

#ifdef EDITOR
#include <backends/imgui_impl_sdl2.h>
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
    RenderingServer::SetInstance(&renderingServer);
    ResourcesManager::SetInstance(&resourcesManager);
    PhysicsServer::SetInstance(&physicsServer);

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
    // Shutdown editor/renderer resources before destroying SDL objects
    renderingServer.ShutdownImGui();
#ifdef EDITOR
    Editor::Get().ShutdownEditorResources();
#endif

    SDL_DestroyRenderer(renderingServer.renderer);
    SDL_DestroyWindow(renderingServer.window);
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

    // Poll SDL events first and pass them to ImGui
    SDL_Event sdlEvent;
    while (SDL_PollEvent(&sdlEvent))
    {
#ifdef EDITOR
        ImGui_ImplSDL2_ProcessEvent(&sdlEvent);
#endif
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

    renderingServer.Clear();

    uint64_t startUpdateMillis = SDL_GetTicks64();
    sceneTree.Update(deltaTime);
    millisUpdateFrame = SDL_GetTicks64() - startUpdateMillis;

    uint64_t startRenderMillis = SDL_GetTicks64();
    renderingServer.Render();
    millisRenderFrame = SDL_GetTicks64() - startRenderMillis;

    millisFrame = SDL_GetTicks64() - millisecondPreviousFrame;
}
