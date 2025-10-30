#pragma once

class RenderingServer3D
{
public:
    
    
    static void SetInstance(RenderingServer3D* instance) { s_instance = instance; }
    static RenderingServer3D& Get() { return *s_instance; }
    RenderingServer3D(const RenderingServer3D&) = delete;
    RenderingServer3D& operator=(const RenderingServer3D&) = delete;
private:
    static RenderingServer3D* s_instance;
};
