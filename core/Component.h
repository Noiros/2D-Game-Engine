#pragma once
#include <functional>
#include <SDL_render.h>
#include <glm.hpp>
#include <map>
#include <string_view>
#include "./Proprety.h"
#include "Logger.h"
#include "Object.h"

class GameObject;

class Component : public Object
{
public:
    Component() = default;
    virtual ~Component() = default;

    GameObject* gameObject;
    int ZOrder = 0;

    virtual void Ready() {}
    virtual void Update(float deltaTime) {}
    virtual void Render(SDL_Renderer* renderer, glm::vec2 cameraPos, float cameraScale) {}
    virtual void Bind() {}

    template<typename T>
    void BindProperty(std::string_view name, Proprety* prop, T* varPtr)
    {
        prop->varPtr = varPtr;
        properties[name] = prop;
    }

    void SetProperty(std::string_view name, glm::vec2 value) { *static_cast<glm::vec2*>(properties[name]->varPtr) = value; }
    void SetProperty(std::string_view name, int value) { *static_cast<int*>(properties[name]->varPtr) = value; }
    void SetProperty(std::string_view name, float value) { *static_cast<float*>(properties[name]->varPtr) = value; }
    void SetProperty(std::string_view name, bool value) { *static_cast<bool*>(properties[name]->varPtr) = value; }
    
    template<typename T>
    T GetProperty(std::string_view name)
    {
        if (properties.find(name) == properties.end()) return T{};
        return *static_cast<T*>(properties[name]->varPtr);
    }

private:
    std::map<std::string_view, Proprety*> properties;
};

