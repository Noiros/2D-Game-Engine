#pragma once
#include "../../core/Modules/InputManager.h"
#include "../../core/Modules/PhysicsServer.h"
#include "../../core/Modules/RenderingServer.h"
#include "../../core/Modules/ResourcesManager.h"
#include "../../core/Modules/SceneTree.h"

class Engine
{
public:
    PhysicsServer physicsServer;
    RenderingServer renderingServer;
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
