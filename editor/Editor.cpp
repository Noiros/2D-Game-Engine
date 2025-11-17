#include "Editor.h"
#include "Engine.h"
#include "utils/Logger.h"

int main(int argc, char *argv[]) {
    Logger::Log("Editor started");

    auto* engine = new Engine();
    Engine::SetInstance(engine);
    Engine::Get().Initialize();

    return 0;
}