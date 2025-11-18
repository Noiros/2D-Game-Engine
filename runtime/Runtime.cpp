#include "Runtime.h"
#include "Engine.h"
#include "utils/Logger.h"

Runtime::Runtime() {
    auto* engine = new Engine();
    Engine::SetInstance(engine);
    engine->Initialize(this);
}

void Runtime::Ready() {
    Logger::Log("Runtime Ready");
}

void Runtime::Update() {
    Logger::Log("Runtime Update");

}