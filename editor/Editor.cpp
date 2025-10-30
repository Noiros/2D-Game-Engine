#include "Editor.h"
#include <imgui.h>
#include <SDL_render.h>
#include "../game/Game.h"

Editor* Editor::s_instance = nullptr;

void Editor::ShutdownEditorResources()
{
    viewport.Shutdown();
}

void Editor::RenderUI()
{
    viewport.RenderUI();
}
