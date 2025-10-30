#pragma once
#include "modules/InputManager.h"
#include "modules/PhysicsServer2D.h"
#include "modules/RenderingServer2D.h"
#include "modules/RenderingServerUI.h"
#include "modules/ResourcesManager.h"
#include "modules/SceneTree.h"

class Engine
{
public:
    PhysicsServer2D physicsServer2D;
    RenderingServer2D renderingServer2D;
    RenderingServerUI renderingServerUI;
    ResourcesManager resourcesManager;
    InputManager inputManager;
    SceneTree sceneTree;

    Engine();
    ~Engine();
    
    uint64_t millisFrame = 0;
    uint64_t millisUpdateFrame = 0;
    uint64_t millisRenderFrame = 0;
    
    static void SetInstance(Engine* instance) { s_instance = instance; };
    static Engine& Get() { return *s_instance; };
    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;
    
    void Setup();
    void Run();
    void Quit();

private:
    static Engine* s_instance;

    bool isRunning;
    uint64_t millisecondPreviousFrame = 0;

    void Update();
};
