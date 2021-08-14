#pragma once
#include "Window.h"
#include "Event/Event.h"
#include "Event/ApplicationEvent.h"
#include <string>
#include <iostream>

class Application {
public:
	Application(const std::string& name, unsigned int width, unsigned int height);
	Window& getWindow() { return m_window; };


	void onEvent(Event& e);
	void onWindowResize(WindowResizeEvent& e);
	void onWindowClose(WindowCloseEvent& e);
	void onKeyPressed(KeyPressedEvent& e);
	void onKeyReleased(KeyReleasedEvent& e);
	void onKeyRepeated(KeyRepeatedEvent& e);

	void run();

private:
	Window m_window;
	std::string m_name;
};