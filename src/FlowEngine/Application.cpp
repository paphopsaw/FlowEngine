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
	case EventType::MouseButtonPressed:
		this->onMouseButtonPressed(static_cast<MouseButtonPressedEvent&>(e));
		break;
	case EventType::MouseButtonReleased:
		this->onMouseButtonReleased(static_cast<MouseButtonReleasedEvent&>(e));
		break;
	case EventType::MouseMoved:
		this->onMouseMoved(static_cast<MouseMovedEvent&>(e));
		break;
	case EventType::MouseScrolled:
		this->onMouseScrolled(static_cast<MouseScrolledEvent&>(e));
		break;
	}
}

void Application::onWindowResize(WindowResizeEvent& e) {
	std::cout << e <<"\n";
}
void Application::onWindowClose(WindowCloseEvent& e) {
	std::cout << e << "\n";
}



void Application::run() {
	std::vector<float> positions{
		-0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f
	};

	std::vector<unsigned int> indices{
		0, 1, 3,
		3, 2, 0
	};
	Shader shader("../../../resources/shaders/shader.vs", "../../../resources/shaders/shader.fs");
	shader.bind();
	Mesh mesh(positions, indices);


	while (m_window.isRunning())
	{
		m_window.clear();
		mesh.bindVAO();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		m_window.onUpdate();
	}
	m_window.shutdown();
}