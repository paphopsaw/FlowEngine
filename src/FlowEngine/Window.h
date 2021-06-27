#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <stdexcept>
#include <iostream>
#include <cassert>


struct WindowProps {
	unsigned int width;
	unsigned int height;
	std::string name;
	bool vSyncEnabled;
};

class Window {
public:
	Window(unsigned int width, unsigned int height, std::string& name);
	~Window();
	void makeCurrent();
	void update();
	bool shouldClose();
	void shutdown();
	void setVSync(bool enabled);
	bool isVSync() const;
	void clear(float r = 0.05f, float g = 0.05f, float b = 0.05f, float a = 1.0f);

private:

	static bool glfwInitialized;
	static unsigned int numActiveWindows;
	GLFWwindow* window;
	void init();
	WindowProps props;
};