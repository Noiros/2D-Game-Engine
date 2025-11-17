#pragma once
#include <vector>
#include "modules/Window.h"

class Engine {
public:
    Engine() = default;
    ~Engine() = default;

    void Initialize();
    void Run();
    void Update();

    std::vector<Window> windows;

    static void SetInstance(Engine* instance) { s_instance = instance; };
    static Engine& Get() { return *s_instance; };
    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;

private:
    static Engine* s_instance;
};

