#pragma once
#include "Window.h"
#include "Event/Event.h"
#include "Event/ApplicationEvent.h"
#include "Rendering/Scene.h"
#include "Rendering/Mesh.h"
#include "Rendering/Shader.h"
#include "Rendering/ViewerCameraController.h"
#include "Rendering/ResourceManager.h"
#include "Rendering/Renderer.h"
#include "Rendering/Scene.h"
#include "Geometries/Cube.h"
#include "Geometries/Sphere.h"
#include "Geometries/Plane.h"
#include "Physics/Particle.h"
#include <string>
#include <iostream>
#include <glm/glm.hpp>

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
	float m_timeStep = 0;
	float m_lastFrameTime;
	Window m_window;
	ViewerCameraController m_cameraController;
	Scene m_scene;
	std::string m_name;
};