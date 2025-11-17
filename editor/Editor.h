#pragma once
#include "../core/Engine.h"
#include "panels/EditorViewport.h"

class Editor
{
public:
    Editor();
    
    static void SetInstance(Editor* instance) { s_instance = instance; }
    static Editor& Get() { return *s_instance; }


private:
    static Editor* s_instance;
    Engine* engine = nullptr;

    RenderingServer* rendering_server = nullptr;

    // Panels
    EditorViewport viewport;
};
