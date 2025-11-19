#pragma once
#include "SceneTree.h"
#include "Window.h"

class RenderingServer2D {
public:
    RenderingServer2D() = default;

    void Initialize();
    void Render();

    // Create singleton
    static void SetInstance(RenderingServer2D* instance) { s_instance = instance; }
    static RenderingServer2D& Get() { return *s_instance; }
    RenderingServer2D(const RenderingServer2D&) = delete;
    RenderingServer2D& operator=(const RenderingServer2D&) = delete;

private:
    static RenderingServer2D* s_instance;
    SceneTree* sceneTree;
    Window* window;
};
