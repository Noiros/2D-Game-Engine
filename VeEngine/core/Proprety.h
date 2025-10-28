#pragma once
#include <string>

enum PropretyType { Int, Float, String, Vector2, Bool };

struct Proprety
{
    Proprety(PropretyType type) : type(type) {}

    void* varPtr;
    
    PropretyType type;
};
