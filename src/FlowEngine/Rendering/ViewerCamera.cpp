#include "ViewerCamera.h"

const glm::mat4 ViewerCamera::getViewMatrix() const {
	//TODO: Fix this
	glm::mat4 viewMatrix = glm::mat4(1.0f);
	glm::vec3 up = glm::vec3(0.0f, cos(glm::radians(m_declination)), sin(glm::radians(m_declination)));

	viewMatrix = glm::translate(viewMatrix, glm::vec3(0.0f, 0.0f, m_zoom));
	viewMatrix = glm::rotate(viewMatrix, glm::radians(azimuth), up);
	viewMatrix = glm::rotate(viewMatrix, glm::radians(declination), glm::vec3(1.0f, 0.0f, 0.0f));
	return viewMatrix;
}

void ViewerCamera::setAspectRatio(float aspectRatio) {
	m_aspectRation = aspectRatio;
	m_projectionMatrix = glm::perspective(glm::radians(m_fov), aspectRatio, m_nearClip, m_farClip);
}

void ViewerCamera::tilt(const float& delta) {
	m_declination += delta;
	if (m_declination > 89.0f)
		m_declination = 89.0f;
	else if (m_declination < -89.0f)
		m_declination = -89.0f;
}

void ViewerCamera::move(const glm::vec2& delta) {

	//TODO: Note: When moving, delta should be adjusted according to tilting status
}