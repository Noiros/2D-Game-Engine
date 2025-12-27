#include "Sprite2D.h"

#include "Transform2D.h"
#include "../GameObject.h"


void Sprite2D::Ready() {
    transform = &gameObject->GetComponent<Transform2D>();
}

void Sprite2D::Render(SDL_Renderer* renderer) {
    SDL_FRect dest = {0, 0, 150, 150};
    SDL_SetRenderDrawColor(renderer, 255, 28, 43, 255);
    SDL_RenderFillRect(renderer, &dest);
}

void Sprite2D::Update(float delta) {

}

