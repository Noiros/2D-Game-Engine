#include "Editor.h"

#include "imgui.h"

Editor* Editor::s_instance = nullptr;

Editor::Editor()
{
    rendering_server = &RenderingServer::Get();
    
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    //ImGui_ImplSDL2_InitForOpenGL(rendering_server->window, rendering_server->gl_context);
}