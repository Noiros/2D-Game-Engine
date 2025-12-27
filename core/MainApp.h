#pragma once

class MainApp {
public:
    virtual ~MainApp() = default;
    virtual void Ready() = 0;
    virtual void Update() = 0;
};