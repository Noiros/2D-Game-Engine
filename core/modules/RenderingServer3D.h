#pragma once
#include "RenderingServer.h"

class RenderingServer3D
{
public:
    RenderingServer3D() = default;
    ~RenderingServer3D() = default;
    
    static void SetInstance(RenderingServer3D* instance) { s_instance = instance; }
    static RenderingServer3D& Get() { return *s_instance; }
    RenderingServer3D(const RenderingServer3D&) = delete;
    RenderingServer3D& operator=(const RenderingServer3D&) = delete;

private:
    static RenderingServer3D* s_instance;
};
