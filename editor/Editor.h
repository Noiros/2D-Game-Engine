#pragma once
#include "MainApp.h"
#include "modules/EditorInterface.h"

class Editor : public MainApp {
public:
    Editor();
    void Ready() override;
    void Update() override;

    EditorInterface editorInterface;
};
