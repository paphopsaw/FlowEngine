#pragma once
#include "ViewerCamera.h"
#include "Event/MouseEvent.h"
#include "Event/ApplicationEvent.h"


class ViewerCameraController {
public:
	enum CameraControlMode {
		OFF,
		ROTATE,
		MOVE
	};
	ViewerCameraController();
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
	CameraControlMode m_mode;
	float m_scrollSensitivity = 1.0f;
	float m_mouseMoveSensitivity = 1.0f;
	float m_mouseRotateSensitivity = 1.0f;
	float m_mousePosX = 0.0f;
	float m_mousePosY = 0.0f;
};

