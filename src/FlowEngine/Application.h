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
	void onKeyPressed(KeyPressedEvent& e) { std::cout << e << "\n"; }
	void onKeyReleased(KeyReleasedEvent& e) { std::cout << e << "\n"; }
	void onKeyRepeated(KeyRepeatedEvent& e) { std::cout << e << "\n"; }
	void onMouseMoved(MouseMovedEvent& e) { std::cout << e << "\n"; }
	void onMouseButtonPressed(MouseButtonPressedEvent& e) { std::cout << e << "\n"; }
	void onMouseButtonReleased(MouseButtonReleasedEvent& e) { std::cout << e << "\n"; }
	void onMouseScrolled(MouseScrolledEvent& e) { std::cout << e << "\n"; }

	void run();

private:
	Window m_window;
	std::string m_name;
};