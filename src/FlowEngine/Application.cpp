#include "Application.h"

Application::Application(const std::string& name, unsigned int width, unsigned int height)
	: m_name{ name }, m_window{ Window(name, width, height) } {
	m_window.setEventCallback([this](Event& e) -> void { this->onEvent(e); });
	m_window.setVSync(true);

}

void Application::onEvent(Event& e) {
	//Change to switch-case
	if (e.getType() == EventType::WindowResize)
		this->onWindowResize(static_cast<WindowResizeEvent&>(e));
	else if (e.getType() == EventType::WindowClose)
		this->onWindowClose(static_cast<WindowCloseEvent&>(e));
}

void Application::onWindowResize(WindowResizeEvent& e) {
	std::cout << "Resize : (" << e.getHeight() << ", " << e.getWidth() << ")\n";
}
void Application::onWindowClose(WindowCloseEvent& e) {
	std::cout << "Close" << "\n";
}

void Application::run() {
	while (m_window.isRunning())
	{
		m_window.clear();

		m_window.onUpdate();
	}
	m_window.shutdown();
}