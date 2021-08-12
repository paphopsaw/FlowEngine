#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <vector>
#include "Window.h"
#include "Application.h"

int main() {
    unsigned int width{ 1280 };
    unsigned int height{ 720 };
    std::string name{ "Demo" };
    Application app(name, width, height);
    app.run();
}