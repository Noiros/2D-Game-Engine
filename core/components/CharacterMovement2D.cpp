#include "CharacterMovement2D.h"
#include "../modules/PhysicsServer.h"
#include "Collider2D.h"
#include "../GameObject.h"

void CharacterMovement2D::Update(float deltaTime)
{
    if (transform == nullptr) return;

    glm::vec2 position = transform->GetProperty<glm::vec2>("position");
    
    if (gameObject->HasComponent<Collider2D>())
    {
        if (gameObject->GetComponent<Collider2D>().isTrigger)
        {
            Collider2D* collider = PhysicsServer::Get().TestMovement(&gameObject->GetComponent<Collider2D>(), velocity * deltaTime);
            if (collider != nullptr) gameObject->HitObject(collider->gameObject);
            position += velocity * deltaTime;
        }
        else
        {
            Collider2D* collider;
            collider = PhysicsServer::Get().TestMovement(&gameObject->GetComponent<Collider2D>(), glm::vec2(velocity.x, 0) * deltaTime);
            if (collider == nullptr)
            {
                position.x += velocity.x * deltaTime;
            }
            else
            {
                gameObject->HitObject(collider->gameObject);
            }
            collider = PhysicsServer::Get().TestMovement(&gameObject->GetComponent<Collider2D>(), glm::vec2(0, velocity.y) * deltaTime);
            if (collider == nullptr)
            {
                position.y += velocity.y * deltaTime;
            }
            else
            {
                gameObject->HitObject(collider->gameObject);
            }
        }
    } else
    {
        position += velocity * deltaTime;
    }

    transform->SetProperty("position", position);
}

void CharacterMovement2D::Ready()
{
    transform = &gameObject->GetComponent<Transform2D>();
}
