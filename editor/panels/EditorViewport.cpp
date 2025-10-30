#include "EditorViewport.h"

#include <imgui.h>
#include <SDL_render.h>

#include "../../core/Engine.h"
#include "../../core/modules/RenderingServer2D.h"
#include "../../core/modules/SceneTree.h"
#include "../../game/Game.h"

void EditorViewport::Setup(Engine* engine)
{
    m_engine = engine;
}

void EditorViewport::Shutdown()
{
    if (m_viewportTexture)
    {
        SDL_DestroyTexture(m_viewportTexture);
        m_viewportTexture = nullptr;
        m_viewportWidth = m_viewportHeight = 0;
    }
}

void EditorViewport::EnsureViewportTexture(int width, int height)
{
    if (m_viewportTexture && (m_viewportWidth == width && m_viewportHeight == height))
        return;

    // Recreate if size changed
    if (m_viewportTexture)
    {
        SDL_DestroyTexture(m_viewportTexture);
        m_viewportTexture = nullptr;
    }

    m_viewportWidth = width;
    m_viewportHeight = height;

    SDL_Renderer* sdlRenderer = m_engine->renderingServer2D.renderer;
    m_viewportTexture = SDL_CreateTexture(
        sdlRenderer,
        SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_TARGET,
        m_viewportWidth,
        m_viewportHeight);

    if (m_viewportTexture)
    {
        SDL_SetTextureBlendMode(m_viewportTexture, SDL_BLENDMODE_BLEND);
    }
}

void EditorViewport::RenderUI()
{    
    if (!m_engine)
        return;

    // 1) Render the scene into an off-screen texture
    if (m_engine->renderingServer2D.camera != nullptr)
    {
        EnsureViewportTexture(DISPLAY_WIDTH, DISPLAY_HEIGHT);

        SDL_Renderer* sdlRenderer = m_engine->renderingServer2D.renderer;
        SDL_SetRenderTarget(sdlRenderer, m_viewportTexture);
        SDL_SetRenderDrawColor(sdlRenderer, 29, 28, 43, 255);
        SDL_RenderClear(sdlRenderer);

        glm::vec2 cameraPos = m_engine->renderingServer2D.camera->GetCameraPos() - glm::vec2(DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2);
        SceneTree::Get().Render(sdlRenderer, cameraPos, m_engine->renderingServer2D.camera->GetCameraScale());

        SDL_SetRenderTarget(sdlRenderer, nullptr);
    }

    // 2) Draw the editor window (Game Viewport) and show the texture
    ImGui::SetNextWindowSize(ImVec2(600, 400), ImGuiCond_FirstUseEver);
    if (ImGui::Begin("Game Viewport", nullptr, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse))
    {
        ImVec2 avail = ImGui::GetContentRegionAvail();
        const float gameAspect = (float)DISPLAY_WIDTH / (float)DISPLAY_HEIGHT;
        float drawW = avail.x;
        float drawH = drawW / gameAspect;
        if (drawH > avail.y)
        {
            drawH = avail.y;
            drawW = drawH * gameAspect;
        }

        ImVec2 cursorPos = ImGui::GetCursorPos();
        ImGui::SetCursorPos(ImVec2(cursorPos.x + (avail.x - drawW) * 0.5f, cursorPos.y + (avail.y - drawH) * 0.5f));

        if (m_viewportTexture)
        {
            ImGui::Image((ImTextureID)m_viewportTexture, ImVec2(drawW, drawH));
        }
        else
        {
            ImGui::TextUnformatted("No viewport texture");
        }
    }
    ImGui::End();
}
