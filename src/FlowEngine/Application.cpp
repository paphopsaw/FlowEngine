#include "Application.h"

Application::Application(const std::string& name, unsigned int width, unsigned int height)
	: m_name{ name }, m_window{ Window(name, width, height) } {
	m_window.setEventCallback([this](Event& e) -> void { this->onEvent(e); });
	m_window.setVSync(true);
	m_lastFrameTime = glfwGetTime();
}

void Application::onEvent(Event& e) {
	m_cameraController.onEvent(e, m_timeStep);
}

void Application::run() {
	Sphere sphere;
	Plane plane;
	ResourceManager::loadShader("../../../resources/shaders/shader.vs", "../../../resources/shaders/shader.fs", "myShader");

	Particle particle(2.0f, glm::vec3(10.0f, 0.0f, 0.0f), glm::vec3(-5.0f, 10.0f, 0.0f));
	particle.setAcceleration(glm::vec3(0.0f, -9.8f, 0.0f));

	m_scene.addInstance("sphere",
		{ glm::vec3(0.5f, 0.5f, 0.5f),
		  glm::quat(1.0f, 0.0f, 0.0f, 0.0f),
		  glm::vec3(0.0f, 1.0f, 0.0f)
		},
		{ 32.0f,
		  glm::vec3(1.0f, 0.0f, 0.0f)
		},
		"Ball");

	m_scene.getInstances()["Ball"].transform.translation = particle.getPosition();

	m_scene.addInstance("square",
		{ glm::vec3(20.0f, 20.0f, 20.0f),
		  glm::quat(1.0f, 0.0f, 0.0f, 0.0f),
		  glm::vec3(0.0f, 0.0f, 0.0f)
		},
		{ 128.0f,
		  glm::vec3(0.4f, 0.7f, 0.5f)
		},
		"Floor");

	m_scene.addDirectionalLight(
		{ glm::vec3(0.0f, -1.0f, -1.0f),
		  glm::vec3(0.05f, 0.05f, 0.05f),
		  glm::vec3(0.4f, 0.4f, 0.4f),
		  glm::vec3(0.5f, 0.5f, 0.5f),
		  true
		},
		"Light1");

	m_scene.addPointLight(
		{
		  glm::vec3(2.0f, 4.0f, -2.0f),
		  glm::vec3(0.05f, 0.05f, 0.05f),
		  glm::vec3(0.4f, 0.4f, 0.4f),
		  glm::vec3(0.5f, 0.5f, 0.5f),
		  1.0f,
		  0.4f,
		  0.032f,
		  true
		},
		"Light2");

	Renderer renderer;
	m_cameraController.getCamera().tilt(30);
	m_cameraController.getCamera().rotate(45);
	m_cameraController.getCamera().zoom(20);

	while (m_window.isRunning())
	{
		float time = glfwGetTime();
		m_timeStep = time - m_lastFrameTime;
		m_lastFrameTime = time;

		//Update particle
		particle.integrate(m_timeStep);
		m_scene.getInstances()["Ball"].transform.translation = particle.getPosition();

		//Draw
		m_window.clear();
		renderer.draw(ResourceManager::getShader("myShader"), m_scene, m_cameraController.getCamera());

		m_window.onUpdate();
	}
	m_window.shutdown();
}