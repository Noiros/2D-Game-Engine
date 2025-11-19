#pragma once
#define EDITOR
#include <vector>

#include "MainApp.h"
#include "modules/Event.h"
#include "modules/RenderingServer2D.h"
#include "modules/RenderingServer3D.h"
#include "modules/SceneTree.h"
#include "modules/Window.h"

class Engine {
public:
    Engine() = default;
    ~Engine() = default;

    void Initialize(MainApp* main_app);
    void Run();
    void MainLoop();

    Window* GetMainWindow() { return &windows[0]; }
    Window* GetWindow(int windowIDX) { return &windows[windowIDX]; }

    static void SetInstance(Engine* instance) { s_instance = instance; };
    static Engine& Get() { return *s_instance; };
    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;

private:
    static Engine* s_instance;

    MainApp* mainApp;
    std::vector<Window> windows;
    SceneTree sceneTree;
    Event event;
    RenderingServer2D rendering_server_2d;
    RenderingServer3D rendering_server_3d;
};

