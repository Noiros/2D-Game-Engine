#include "Sprite2D.h"

#include "Transform2D.h"
#include "../Engine.h"
#include "../GameObject.h"


void Sprite2D::Ready()
{
    transform = &gameObject->GetComponent<Transform2D>();
}

void Sprite2D::Render()
{

}

void Sprite2D::Update(float delta) {
    Component2D::Update(delta);
    Logger::Log("Updating Sprite2D");
}

