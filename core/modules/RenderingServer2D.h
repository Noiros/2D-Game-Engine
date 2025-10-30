#pragma once
#include <SDL_rect.h>
#include <SDL_render.h>
#include <vec2.hpp>
#include <vector>

#include "../Component.h"
#include "../components/Camera2D.h"


class RenderingServer2D
{
    public:
        RenderingServer2D();
        ~RenderingServer2D();
    
        static void SetInstance(RenderingServer2D* instance) { s_instance = instance; }
        static RenderingServer2D& Get() { return *s_instance; }
        RenderingServer2D(const RenderingServer2D&) = delete;
        RenderingServer2D& operator=(const RenderingServer2D&) = delete;

        SDL_Renderer* GetRenderer() const { return renderer; }
        void Render();
        void Clear();

        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        Camera2D* camera;

    private:
        static RenderingServer2D* s_instance;
        std::vector<Component*> orderedComponents;
};
