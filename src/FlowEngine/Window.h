#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <stdexcept>
#include <iostream>
#include <cassert>
#include <functional>
#include <Event/Event.h>
#include <Event/KeyEvent.h>
#include <Event/ApplicationEvent.h>



class Window {
public:
	using EventCallback = std::function<void(Event&)>;
	Window(const std::string& name, unsigned int width, unsigned int height);
	~Window();
	void onUpdate();
	bool isRunning();
	void shutdown();
	void setVSync(bool enabled);
	bool isVSync() const;
	void clear(float r = 0.05f, float g = 0.05f, float b = 0.05f, float a = 1.0f);
	void setEventCallback(EventCallback callback);

private:
	static bool glfwInitialized;
	static unsigned int numActiveWindows;
	GLFWwindow* m_window;
	void init();
	struct WindowProps {
		unsigned int width;
		unsigned int height;
		std::string name;
		bool vSyncEnabled;
		EventCallback callback;
	};
	WindowProps props;
};