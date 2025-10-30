#include "RenderingServer.h"

#include <algorithm>
#include <fwd.hpp>
#include <SDL_render.h>
#include <SDL_ttf.h>

#include "../../game/Game.h"
#include "SceneTree.h"

#include "../Logger.h"

#ifdef EDITOR
#include <imgui.h>
#include <backends/imgui_impl_sdl2.h>
#include <backends/imgui_impl_sdlrenderer2.h>
#include "../../editor/Editor.h"
#endif

RenderingServer* RenderingServer::s_instance = nullptr;


RenderingServer::RenderingServer()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        Logger::Err("Error initializing SDL!");
        return;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    
    window = SDL_CreateWindow("Enter the CPP", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DISPLAY_WIDTH, DISPLAY_HEIGHT,
                              SDL_WINDOW_RESIZABLE);
    if (!window)
    {
        Logger::Err("Error creating SDL Window!");
        return;
    }
    TTF_Init();

#ifdef VSYNC
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
#else
    renderer = SDL_CreateRenderer(window, -1, 0);
#endif // VSYNC

    if (!renderer)
    {
        Logger::Err("Error creating SDL Renderer!");
        return;
    }

#ifdef EDITOR
    // Initialize ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    if (!ImGui_ImplSDL2_InitForSDLRenderer(window, renderer))
    {
        Logger::Err("ImGui_ImplSDL2_InitForSDLRenderer failed");
    }
    else if (!ImGui_ImplSDLRenderer2_Init(renderer))
    {
        Logger::Err("ImGui_ImplSDLRenderer2_Init failed");
    }
    else
    {
        m_imguiInitialized = true;
        Logger::Log("ImGui initialized (SDL2 + SDL_Renderer).");
    }
#endif

    Logger::Log("Rendering server initialized.");
}

void RenderingServer::Clear()
{
    //clear draw buffer
    SDL_SetRenderDrawColor(renderer, 29, 28, 43, 255);
    SDL_RenderClear(renderer);
}

void RenderingServer::Render()
{
#ifndef EDITOR
    // Non-editor: render scene directly to backbuffer
    if (camera != NULL)
    {
        glm::vec2 cameraPos = camera->GetCameraPos() - glm::vec2(DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2);
        SceneTree::Get().Render(renderer, cameraPos, camera->GetCameraScale());
    }
#else
    // Editor: build ImGui frame and delegate UI (including viewport) to Editor module
    if (m_imguiInitialized)
    {
        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        // Delegate editor UI (will render scene into an off-screen texture and draw it)
        Editor::Get().RenderUI();

        // Render ImGui draw data
        ImGui::Render();
        ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), renderer);
    }
#endif

    SDL_RenderPresent(renderer);
}

RenderingServer::~RenderingServer()
{
    ShutdownImGui();
}

void RenderingServer::ShutdownImGui()
{
#ifdef EDITOR
    if (m_imguiInitialized)
    {
        ImGui_ImplSDLRenderer2_Shutdown();
        ImGui_ImplSDL2_Shutdown();
        ImGui::DestroyContext();
        m_imguiInitialized = false;
        Logger::Log("ImGui shutdown done.");
    }
#endif
}
