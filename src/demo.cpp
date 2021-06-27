#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <vector>
#include "Window.h"
#include "Buffer.h"
#include "VertexArray.h"

int main() {
    int width{ 1080 };
    int height{ 720 }; 
    std::string windowName{ "Hello world" };
    Window myWindow(width, height, windowName);

    std::vector<float> vertices {
     -0.5f, -0.5f, 0.0f,
      0.5f, -0.5f, 0.0f,
     -0.5f,  0.5f, 0.0f,
      0.5f,  0.5f, 0.0f,
    };

    std::vector<unsigned int> indices {
      0, 1, 3,
      0, 3, 2
    };

    std::vector<unsigned int> layout{ 3 };

    VertexBuffer vertexBuffer(vertices);
    vertexBuffer.setLayout(layout);
    IndexBuffer indexBuffer(indices);


    while (!myWindow.shouldClose())
    {
        myWindow.clear();
        //Draw something


        myWindow.update();
    }

    myWindow.shutdown();
}