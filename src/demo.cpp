#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include "Window.h"

int main() {
    int width{ 640 };
    int height{ 480 }; 
    std::string windowName{ "Hello world" };
    Window myWindow(width, height, windowName);

    /* Loop until the user closes the window */
    while (!myWindow.shouldClose())
    {
        /* Render here */
        myWindow.clear();
        /* Swap front and back buffers */
        myWindow.update();
    }

    myWindow.shutdown();
}