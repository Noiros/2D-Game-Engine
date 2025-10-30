#include "Transform2D.h"

void Transform2D::Update(float deltaTime)
{
}

void Transform2D::Bind()
{
    Component2D::Bind();

    BindProperty("position", new Proprety(PropretyType::Vector2), &position);
}

void Transform2D::Ready()
{
}

