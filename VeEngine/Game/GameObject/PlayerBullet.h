#pragma once

#include "../../core/GameObject.h"
#include "../../core/Components/AnimatedSprite2D.h"
#include "../../core/Components/CharacterMovement2D.h"

class PlayerBullet : public GameObject
{    
public:
    float bulletSpeed = 2.0f;
    
    PlayerBullet(glm::vec2 dir, GameObject* s) : direction(dir), shooterObject(s) {}
    
    void Ready() override;
    void HitObject(GameObject* other) override;

    AnimatedSprite2D* animatedSprite = nullptr;
    GameObject* shooterObject = nullptr;
    CharacterMovement2D* movement = nullptr;
    glm::vec2 direction = {0, 0};
};