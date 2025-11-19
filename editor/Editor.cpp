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

    editorInterface = EditorInterface();
    editorInterface.InitializeInterface();
}

void Editor::Update() {
    Logger::Log("Editor Update");
    editorInterface.Update();
}