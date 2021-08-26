#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "ViewerCamera.h"
#include "Event/MouseEvent.h"
#include "Event/ApplicationEvent.h"


class ViewerCameraController {
public:
	enum class CameraControlMode {
		OFF,
		ROTATE,
		MOVE
	};
	ViewerCameraController() = default;
	void onEvent(Event& e);

	ViewerCamera& getCamera() { return m_camera; }
	

private:
	void onWindowResize(WindowResizeEvent& e);
	void onMouseScrolled(MouseScrolledEvent& e);
	void onMouseButtonPressed(MouseButtonPressedEvent& e);
	void onMouseButtonReleased(MouseButtonReleasedEvent& e);
	void onMouseMoved(MouseMovedEvent& e);


private:
	ViewerCamera m_camera;
	CameraControlMode m_mode = CameraControlMode::OFF;
	float m_scrollSensitivity = 1.0f;
	float m_mouseMoveSensitivity = 0.01f;
	float m_mouseRotateSensitivity = 30.0f;
	float m_mousePosX = 0.0f;
	float m_mousePosY = 0.0f;
};

