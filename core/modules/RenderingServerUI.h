#pragma once

#include <SDL_events.h>
#include <SDL_render.h>
#include <vector>

#include "../../editor/EditorInterface.h"
#include "../components/ComponentUI.h"

class RenderingServerUI
{
public:
    RenderingServerUI() = default;
    ~RenderingServerUI() = default;

    static void SetInstance(RenderingServerUI* instance) { s_instance = instance; }
    static RenderingServerUI& Get() { return *s_instance; }
    RenderingServerUI(const RenderingServerUI&) = delete;
    RenderingServerUI& operator=(const RenderingServerUI&) = delete;

    void Initialize(SDL_Window* window, SDL_Renderer* renderer);
    void Shutdown();
    void ProcessEvent(const SDL_Event& e);

    
    
    void Render();

    void AddEditorInterface(EditorInterface* editorInterface);
    void AddComponentUI(ComponentUI* componentUI);

    

private:
    static RenderingServerUI* s_instance;

    SDL_Window* m_window = nullptr;
    SDL_Renderer* m_renderer = nullptr;
    bool m_imguiInitialized = false;

    std::vector<EditorInterface*> editorInterfaces;
    std::vector<ComponentUI*> uiComponents;
};
