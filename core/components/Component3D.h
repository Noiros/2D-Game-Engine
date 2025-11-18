#pragma once
#include "Component.h"

class Component3D : public Component {
public:
    void validateComponent() {
        SceneTree::Get().component3DList.push_back(this);
    }
};
