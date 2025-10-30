#pragma once
#include "../core/Engine.h"
#include <SDL_render.h>
#include "panels/EditorViewport.h"

class Editor
{
public:
    void Setup(Engine* _engine) {
        engine = _engine;
        s_instance = this;
        viewport.Setup(_engine);
    }

    static void SetInstance(Editor* instance) { s_instance = instance; }
    static Editor& Get() { return *s_instance; }

    void RenderUI();
    void ShutdownEditorResources();
    
    static Editor* s_instance;

private:
    Engine* engine = nullptr;

    // Panels
    EditorViewport viewport;
};
