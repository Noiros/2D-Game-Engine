#include "Runtime.h"
#include "Engine.h"

void Initialize() {
    auto* engine = new Engine();
    Engine::SetInstance(engine);
    engine->Initialize(this);

    return 0;
}