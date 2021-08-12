#pragma once
#include "Window.h"
#include "Event/Event.h"
#include <string>
#include <iostream>

class Application {
public:
	Application(const std::string& name, unsigned int width, unsigned int height);
	void onEvent(Event& e);
	Window& getWindow() { return m_window; };
	void run();

private:
	Window m_window;
	std::string m_name;
};