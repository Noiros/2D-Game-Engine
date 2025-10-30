#pragma once
#include "../core/Engine.h"
#include <SDL_render.h>

class Editor
{
public:
    void Setup(Engine* _engine) { engine = _engine; s_instance = this; }

    static void SetInstance(Editor* instance) { s_instance = instance; }
    static Editor& Get() { return *s_instance; }

    void RenderUI();
    void ShutdownEditorResources();
    
    static Editor* s_instance;

private:
    Engine* engine = nullptr;

    // Viewport resources (only used when EDITOR is defined)
    SDL_Texture* m_viewportTexture = nullptr;
    int m_viewportWidth = 0;
    int m_viewportHeight = 0;

    void EnsureViewportTexture(int width, int height);
};
