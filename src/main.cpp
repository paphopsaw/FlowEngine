#include "Vector2D.h"
#include "Vector3D.h"
#include <iostream>

int main() {
    Vector3D v1{ 1.0f, 2.0f, 4.0f };
    Vector3D v2{ 0.0f, 1.0f, -1.0f };
    std::cout << v1.dot(v2) << "\n";
}