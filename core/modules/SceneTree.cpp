#include "SceneTree.h"
#include "GameObject.h"
#include "utils/Logger.h"

SceneTree* SceneTree::s_instance = nullptr;

GameObject* SceneTree::CreateGameObject(std::string objectName) {
    auto* gameObject = new GameObject();
    gameObject->SetName(objectName);
    objects.push_back(gameObject);
    gameObjectList.push_back(gameObject);
    return gameObject;
}

void SceneTree::DestroyGameObject(std::string objectName) {
    for (GameObject* gameObject : gameObjectList) {
        if (gameObject->GetName() == objectName) {
            Logger::Log("GameObject Destroyed");
        }
    }
}

GameObject* SceneTree::GetGameObject(std::string objectName) {
    for (GameObject* gameObject : gameObjectList) {
        if (gameObject->GetName() == objectName) {
            return gameObject;
        }
    }
    return nullptr;
}
