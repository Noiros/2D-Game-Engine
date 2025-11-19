#include "Editor.h"

#include "Engine.h"
#include "utils/Logger.h"

Editor::Editor() {
    auto* engine = new Engine();
    Engine::SetInstance(engine);
    engine->Initialize(this);
}

void Editor::Ready() {
    Logger::Log("Editor Ready");

    editorInterface = InterfaceBackend();
    editorInterface.InitializeInterface();
}

void Editor::Update() {
    editorInterface.Update();
}