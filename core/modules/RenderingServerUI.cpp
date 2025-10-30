#include "RenderingServerUI.h"

#include <imgui.h>
#include <backends/imgui_impl_sdl2.h>
#include <backends/imgui_impl_sdlrenderer2.h>

#include "../Logger.h"

RenderingServerUI* RenderingServerUI::s_instance = nullptr;

void RenderingServerUI::Initialize(SDL_Window* window, SDL_Renderer* renderer)
{
    m_window = window;
    m_renderer = renderer;

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    if (!ImGui_ImplSDL2_InitForSDLRenderer(window, renderer))
    {
        Logger::Err("ImGui_ImplSDL2_InitForSDLRenderer failed");
        return;
    }
    if (!ImGui_ImplSDLRenderer2_Init(renderer))
    {
        Logger::Err("ImGui_ImplSDLRenderer2_Init failed");
        ImGui_ImplSDL2_Shutdown();
        return;
    }

    m_imguiInitialized = true;
}

void RenderingServerUI::Shutdown()
{
    if (!m_imguiInitialized)
        return;

    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
    m_imguiInitialized = false;
    m_window = nullptr;
    m_renderer = nullptr;
}

void RenderingServerUI::Render()
{
    if (!m_imguiInitialized) return;

    ImGui_ImplSDLRenderer2_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();




    


    ImGui::Render();
    ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), m_renderer);
    SDL_RenderPresent(m_renderer);
}

void RenderingServerUI::ProcessEvent(const SDL_Event& e)
{
    if (!m_imguiInitialized) return;
    ImGui_ImplSDL2_ProcessEvent(&e);
}