#pragma once
#include "Component.h"

class Component2D : public Component {
    void validateComponent() {
        SceneTree::Get().component2DList.push_back(this);
    }
};
