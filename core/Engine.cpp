#include "Engine.h"
#include "utils/Logger.h"

Engine* Engine::s_instance = nullptr;

void Engine::test() {
    Logger::Log("Test Engine");
}
