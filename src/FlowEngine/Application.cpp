#include "Application.h"

Application::Application(const std::string& name, unsigned int width, unsigned int height)
	: m_name{ name }, m_window{ Window(name, width, height) } {
	m_window.setEventCallback([this](Event& e) -> void { this->onEvent(e); });
	m_window.setVSync(true);

}

void Application::onEvent(Event& e) {
	std::cout << "Hello\n";
}

void Application::run() {
	while (m_window.isRunning())
	{
		m_window.clear();

		m_window.onUpdate();
	}
	m_window.shutdown();
}