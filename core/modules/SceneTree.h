#pragma once
#include <vector>
#include <string>

class Object;
class GameObject;
class Component;
class Component3D;
class Component2D;
class ComponentUI;

class SceneTree
{
public:
    SceneTree() = default;
    ~SceneTree() = default;

    GameObject* CreateGameObject(std::string objectName);
    void DestroyGameObject(std::string objectName);
    GameObject* GetGameObject(std::string objectName);

    std::vector<Object*> objects;
    std::vector<GameObject*> gameObjectList;
    std::vector<Component*> componentList;
    std::vector<Component3D*> component3DList;
    std::vector<Component2D*> component2DList;
    std::vector<ComponentUI*> componentUIList;

    // Create singleton
    static void SetInstance(SceneTree* instance) { s_instance = instance; }
    static SceneTree& Get() { return *s_instance; }
    SceneTree(const SceneTree&) = delete;
    SceneTree& operator=(const SceneTree&) = delete;

private:
    static SceneTree* s_instance;
};
