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
	Sphere mySphere;
	Square floor;
	Mesh sphereMesh(mySphere);
	Mesh floorMesh(floor);

	Shader shader("../../../resources/shaders/shader.vs", "../../../resources/shaders/shader.fs");
	shader.bind();

	glm::mat4 proj = m_cameraController.getCamera().getProjectionMatrix();
	shader.setMat4("projection", proj);

	shader.setVec3("dirLight.ambient", 0.05f, 0.05f, 0.05f);
	shader.setVec3("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
	shader.setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);
	shader.setVec3("dirLight.direction", 0.0f, -1.0f, -1.0f);
	shader.setFloat("shininess", 32.0f);
	glm::mat4 modelSphere = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 modelFloor = glm::scale(glm::mat4(1.0f), glm::vec3(20.0f, 20.0f, 20.0f));
	glEnable(GL_DEPTH_TEST);
	while (m_window.isRunning())
	{
		float time = glfwGetTime();
		m_timeStep = time - m_lastFrameTime;
		m_lastFrameTime = time;
		m_window.clear();
		glm::mat4 view = m_cameraController.getCamera().getViewMatrix();
		shader.setMat4("view", view);
		glm::vec3 viewPositions = m_cameraController.getCamera().getPositions();
		shader.setVec3("viewPos", viewPositions);

		sphereMesh.bindVAO();
		shader.setMat4("model", modelSphere);
		glDrawElements(GL_TRIANGLES, sphereMesh.getNumIndices(), GL_UNSIGNED_INT, 0);
		floorMesh.bindVAO();
		shader.setMat4("model", modelFloor);
		glDrawElements(GL_TRIANGLES, floorMesh.getNumIndices(), GL_UNSIGNED_INT, 0);


		m_window.onUpdate();
	}
	m_window.shutdown();
}