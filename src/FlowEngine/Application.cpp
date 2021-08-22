#include "Application.h"

Application::Application(const std::string& name, unsigned int width, unsigned int height)
	: m_name{ name }, m_window{ Window(name, width, height) } {
	m_window.setEventCallback([this](Event& e) -> void { this->onEvent(e); });
	m_window.setVSync(true);
	
}

void Application::onEvent(Event& e) {
	m_cameraController.onEvent(e);
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