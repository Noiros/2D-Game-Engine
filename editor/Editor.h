#pragma once
#include "MainApp.h"
#include "modules/InterfaceBackend.h"

class Editor : public MainApp {
public:
    Editor();
    void Ready() override;
    void Update() override;

    InterfaceBackend editorInterface;
};
