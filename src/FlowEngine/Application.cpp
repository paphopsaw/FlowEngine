#include "Application.h"

Application::Application(const std::string& name, unsigned int width, unsigned int height)
	: m_name{ name }, m_window{ Window(name, width, height) } {
	m_window.setEventCallback([this](Event& e) -> void { this->onEvent(e); });
	m_window.setVSync(true);

}

void Application::onEvent(Event& e) {
	EventType type{ e.getType() };
	switch (type) {
	case EventType::WindowResize:
		this->onWindowResize(static_cast<WindowResizeEvent&>(e));
		break;
	case EventType::WindowClose:
		this->onWindowClose(static_cast<WindowCloseEvent&>(e));
		break;
	case EventType::KeyPressed:
		this->onKeyPressed(static_cast<KeyPressedEvent&>(e));
		break;
	case EventType::KeyReleased:
		this->onKeyReleased(static_cast<KeyReleasedEvent&>(e));
		break;
	case EventType::KeyRepeated:
		this->onKeyRepeated(static_cast<KeyRepeatedEvent&>(e));
		break;
	}
}

void Application::onWindowResize(WindowResizeEvent& e) {
	std::cout << e <<"\n";
}
void Application::onWindowClose(WindowCloseEvent& e) {
	std::cout << e << "\n";
}

void Application::onKeyPressed(KeyPressedEvent& e) {
	std::cout << e << "\n";
}

void Application::onKeyReleased(KeyReleasedEvent& e) {
	std::cout << e << "\n";
}

void Application::onKeyRepeated(KeyRepeatedEvent& e) {
	std::cout << e << "\n";
}

void Application::run() {
	while (m_window.isRunning())
	{
		m_window.clear();

		m_window.onUpdate();
	}
	m_window.shutdown();
}