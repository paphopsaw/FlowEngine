#include "ViewerCameraController.h"

void ViewerCameraController::onEvent(Event& e) {
	EventType type = e.getType();
	switch (type) {
	case EventType::WindowResize:
		this->onWindowResize(static_cast<WindowResizeEvent&>(e));
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


void ViewerCameraController::onWindowResize(WindowResizeEvent& e) {
	float height = e.getHeight();
	float width = e.getWidth();
	m_camera.setAspectRatio(width / height);
}


void ViewerCameraController::onMouseButtonPressed(MouseButtonPressedEvent& e) {
	MouseCode button = e.getMouseButton();
	switch (button) {
	case MouseCode::ButtonLeft:
		if (m_mode == CameraControlMode::OFF)
			m_mode = CameraControlMode::ROTATE;
		break;
	case MouseCode::ButtonMiddle:
		if (m_mode == CameraControlMode::OFF)
			m_mode = CameraControlMode::MOVE;
		break;
	}
}

void ViewerCameraController::onMouseButtonReleased(MouseButtonReleasedEvent& e) {
	MouseCode button = e.getMouseButton();
	switch (button) {
	case MouseCode::ButtonLeft:
		if (m_mode == CameraControlMode::ROTATE)
			m_mode = CameraControlMode::OFF;
		break;
	case MouseCode::ButtonMiddle:
		if (m_mode == CameraControlMode::MOVE)
			m_mode = CameraControlMode::OFF;
		break;
	}
}


void ViewerCameraController::onMouseScrolled(MouseScrolledEvent& e) {
	float delta = e.getOffsetY();
	m_camera.zoom(delta * m_scrollSensitivity);
}

void ViewerCameraController::onMouseMoved(MouseMovedEvent& e) {
	float posX = e.getX();
	float posY = e.getY();
	float dx = posX - m_mousePosX;
	float dy = posY - m_mousePosY;
	m_mousePosX = posX;
	m_mousePosY = posY;
	if (m_mode == CameraControlMode::ROTATE) {
		m_camera.tilt(glm::radians(dy * m_mouseRotateSensitivity));
		m_camera.rotate(glm::radians(dx * m_mouseRotateSensitivity));
	}
	else if (m_mode == CameraControlMode::MOVE) {
		glm::vec2 delta = glm::vec2(dx * m_mouseMoveSensitivity, dy * m_mouseMoveSensitivity);
		m_camera.move(delta);
	}

}