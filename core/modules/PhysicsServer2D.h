#pragma once
#include "../components/Collider2D.h"
#include <map>
#include <vector>

class PhysicsServer2D
{
public:    
    PhysicsServer2D() {}
    ~PhysicsServer2D() {}
    
    void AddCollider(Collider2D* collider, int layer = 0);
    void RmCollider(Collider2D* collider);
    
    Collider2D* TestMovement(Collider2D* collider, glm::vec2 velocity);
    std::vector<Collider2D*> GetOverloppingBodies(Collider2D* collider, int layer);
    bool IsColliding(Collider2D* obj1, Collider2D* obj2);
    bool IsCollidingAABB(SDL_Rect obj1, SDL_Rect obj2);


    //Creer le singleton
    static void SetInstance(PhysicsServer2D* instance) { s_instance = instance; }
    static PhysicsServer2D& Get() { return *s_instance; }
    PhysicsServer2D(const PhysicsServer2D&) = delete;
    PhysicsServer2D& operator=(const PhysicsServer2D&) = delete;

    
private:
    static PhysicsServer2D* s_instance;
    std::map<int, std::vector<Collider2D*>> colliders;
};
