#include "Runtime.h"
#include "Engine.h"
#include "utils/Logger.h"

int main(int argc, char *argv[]) {
    Logger::Log("Runtime started");
    return 0;
}

int Runtime::EntryPoint() {
    auto* engine = new Engine();
    Engine::SetInstance(engine);
    Engine::Get().Initialize();
    return 0;
}