#include "Runtime.h"
#include "Engine.h"
#include "GameObject.h"
#include "components/Sprite2D.h"
#include "utils/Logger.h"

Runtime::Runtime() {
    auto* engine = new Engine();
    Engine::SetInstance(engine);
    engine->Initialize(this);
}

void Runtime::Ready() {
    Logger::Log("Runtime Ready");
    GameObject* test = SceneTree::Get().CreateGameObject("TestGameObject");
    test->AddComponent<Sprite2D>();
}

void Runtime::Update() {

}