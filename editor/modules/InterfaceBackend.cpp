#include "InterfaceBackend.h"
#include <iostream>
#include "Engine.h"
#include "imgui.h"
#include "backends/imgui_impl_sdl3.h"
#include "backends/imgui_impl_opengl3.h"
#include "utils/Logger.h"

void InterfaceBackend::InitializeInterface() {
    SDL_Window* m_window = Engine::Get().GetMainWindow()->window;
    SDL_GLContext m_opengl = Engine::Get().GetMainWindow()->gl_context;

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    if (!ImGui_ImplSDL3_InitForOpenGL(m_window, m_opengl)) {
        Logger::Err("ImGui_ImplSDL3_InitForOpenGL failed");
        ImGui_ImplSDL3_Shutdown();
        return;
    }

    if (!ImGui_ImplOpenGL3_Init("#version 150")) {
        Logger::Err("ImGui_ImplOpenGL3_Init failed");
        ImGui_ImplSDL3_Shutdown();
    }


    Logger::Log("Setup Input Event");
    inputEvent = Event::Get().Subscribe<InputEvent>(
        [this](const InputEvent& e){ ProcessInput(e); }
    );
    Logger::Log("EditorInterface::InitializeInterface - subscribed OK");
}

void InterfaceBackend::Update() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();

    ImGui::ShowDemoWindow();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    SDL_GL_SwapWindow(Engine::Get().GetMainWindow()->window);
}


void InterfaceBackend::ProcessInput(const InputEvent& e) {
    Logger::Log("Process Input Event");
    ImGui_ImplSDL3_ProcessEvent(&e.event);
}