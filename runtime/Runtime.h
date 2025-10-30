#pragma once
#include "../core/Engine.h"

class Runtime
{
public:
    void Setup(Engine* _engine) { engine = _engine; }

private:
    Engine* engine;
    
};
