#pragma once
#define EDITOR
#include <memory>
#include <vector>

#include "MainApp.h"
#include "modules/Window.h"

class Engine {
public:
    Engine() = default;
    ~Engine() = default;

    void Initialize(MainApp* main_app);
    void Run();
    void MainLoop();

    Window* GetMainWindow() { return &windows[0]; }

    MainApp* mainApp;
    std::vector<Window> windows;

    static void SetInstance(Engine* instance) { s_instance = instance; };
    static Engine& Get() { return *s_instance; };
    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;

private:
    static Engine* s_instance;
};

