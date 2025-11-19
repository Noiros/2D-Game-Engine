#pragma once
#include "Engine.h"
#include "EventType.h"
#include "modules/Event.h"
#include "SDL3/SDL_events.h"

class InterfaceBackend {
public:
    void InitializeInterface();
    void Update();

    void ProcessInput(const InputEvent &e);

private:
    Event::Connection inputEvent;
};
