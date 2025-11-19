#include "RenderingServer2D.h"

#include "Engine.h"
#include "components/Component2D.h"

RenderingServer2D* RenderingServer2D::s_instance = nullptr;


void RenderingServer2D::Initialize() {
    sceneTree = &SceneTree::Get();
    window = Engine::Get().GetMainWindow();
}

void RenderingServer2D::Render() {
    SDL_Renderer* renderer = window->renderer;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    for (Component2D* comp : sceneTree->component2DList) {
        comp->Render(renderer);
    }

    SDL_RenderPresent(renderer);
}
