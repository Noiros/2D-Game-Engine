#pragma once
#include "MainApp.h"

class Runtime : public MainApp {
public:
    Runtime();
    void Ready() override;
    void Update() override;
};
