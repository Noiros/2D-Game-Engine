#include "Editor.h"
#include "utils/Logger.h"

Editor::Editor() {
    Logger::Log("Initialize Editor ...");
    engine = &Engine::Get();

    engine->test();
}
