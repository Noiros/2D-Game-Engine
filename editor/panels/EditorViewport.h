#pragma once

#include <SDL_render.h>
#include "../EditorInterface.h"

class Engine;

class EditorViewport : public EditorInterface
{
public:
    void Setup(Engine* engine);
    void Shutdown();
    void RenderUI();

private:
    Engine* m_engine = nullptr;

    SDL_Texture* m_viewportTexture = nullptr;
    int m_viewportWidth = 0;
    int m_viewportHeight = 0;

    void EnsureViewportTexture(int width, int height);
};
