#include "RenderingServer2D.h"

#include <algorithm>
#include <fwd.hpp>
#include <SDL_render.h>
#include <SDL_ttf.h>

#include "../../game/Game.h"
#include "SceneTree.h"

#include "../Logger.h"

RenderingServer2D* RenderingServer2D::s_instance = nullptr;


RenderingServer2D::RenderingServer2D()
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

    Logger::Log("Rendering server initialized.");
}

void RenderingServer2D::Clear()
{
    //clear draw buffer
    SDL_SetRenderDrawColor(renderer, 29, 28, 43, 255);
    SDL_RenderClear(renderer);
}

void RenderingServer2D::Render()
{
#ifndef EDITOR
    // Non-editor: render scene directly to backbuffer and present
    if (camera != NULL)
    {
        glm::vec2 cameraPos = camera->GetCameraPos() - glm::vec2(DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2);
        SceneTree::Get().Render(renderer, cameraPos, camera->GetCameraScale());
    }
    SDL_RenderPresent(renderer);
#else
    // Editor build: 2D server does not own presentation nor ImGui. Scene rendering happens via Editor viewport.
    // Nothing to do here.
#endif
}

RenderingServer2D::~RenderingServer2D()
{
}
