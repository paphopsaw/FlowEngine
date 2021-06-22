#include "Vector2D.h"
#include <iostream>

int main() {
    fe::Vector2D v1{ 1.0f, 2.0f };
    v1 *= 2;
    fe::Vector2D v2{ v1.normalized() };
    std::cout << v1 << "\n";
    std::cout << v2 << "\n";
    std::cout << v1 + 2 * v2 << "\n";
    v1 = v2;
    std::cout << v1 << "\n";
}