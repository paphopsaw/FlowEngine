#include "Application.h"

Application::Application(const std::string& name, unsigned int width, unsigned int height)
	: m_name{ name }, m_window{ Window(name, width, height) } {
	m_window.setEventCallback([this](Event& e) -> void { this->onEvent(e); });
	m_window.setVSync(true);
	m_lastFrameTime = glfwGetTime();
}

void Application::onEvent(Event& e) {
	m_cameraController.onEvent(e);
}

void Application::run() {
	/*std::vector<float> positions{
		-0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f
	};

	std::vector<unsigned int> indices{
		0, 1, 3,
		3, 2, 0
	}; */

	Cube myCube;
	Shader shader("../../../resources/shaders/shader.vs", "../../../resources/shaders/shader.fs");
	shader.bind();
	Mesh mesh(myCube.getPositions(), myCube.getIndices());

	glm::mat4 proj = m_cameraController.getCamera().getProjectionMatrix();
	shader.setMat4("projection", proj);

	glEnable(GL_DEPTH_TEST);
	while (m_window.isRunning())
	{
		float time = glfwGetTime();
		m_timeStep = time - m_lastFrameTime;
		m_lastFrameTime = time;
		m_window.clear();
		mesh.bindVAO();
		glm::mat4 view = m_cameraController.getCamera().getViewMatrix();
		shader.setMat4("view", view);
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
		m_window.onUpdate();
	}
	m_window.shutdown();
}