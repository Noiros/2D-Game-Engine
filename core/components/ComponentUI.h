#pragma once
#include "Component.h"

class ComponentUI : public Component {
public:
    void validateComponent() {
        SceneTree::Get().componentUIList.push_back(this);
    }
};
