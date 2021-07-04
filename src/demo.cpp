#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <vector>
#include "Window.h"
#include "Buffer.h"
#include "VertexArray.h"
#include "Shader.h"


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main() {
    int width{ 1080 };
    int height{ 720 }; 
    std::string windowName{ "Hello world" };
    Window myWindow(width, height, windowName);
    myWindow.setKeyCallback(key_callback);

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

    VertexArray vertexArray;
    vertexArray.addVertexBuffer(vertexBuffer);
    vertexArray.setIndexBuffer(indexBuffer);

    Shader myShader(
        "../../../resources/shaders/shader.vs",
        "../../../resources/shaders/shader.fs");
    myShader.bind();


    while (!myWindow.shouldClose())
    {
        myWindow.clear();
        //Draw something
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        myWindow.update();
    }

    myWindow.shutdown();
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    std::cout << key << "\n";
}