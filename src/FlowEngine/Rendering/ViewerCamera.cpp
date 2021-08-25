#include "ViewerCamera.h"

std::ostream& operator<<(std::ostream& out, glm::vec3 v) {
	out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
	return out;
}

const glm::mat4 ViewerCamera::getViewMatrix() const {
	float sel = glm::sin(glm::radians(m_elevation));
	float cel = glm::cos(glm::radians(m_elevation));
	float saz = glm::sin(glm::radians(m_azimuth));
	float caz = glm::cos(glm::radians(m_azimuth));
	glm::vec3 cameraPos = m_origin +
		glm::vec3(
			m_distance * cel * saz,
			m_distance * sel,
			m_distance * cel * caz);
	glm::vec3 up = glm::vec3(-sel * saz, cel, -sel * caz);
	glm::mat4 viewMatrix = glm::lookAt(cameraPos, m_origin, up);
	std::cout << cameraPos << " " << m_origin << " " << up << "\n";

	return viewMatrix;
}

void ViewerCamera::setAspectRatio(float aspectRatio) {
	m_aspectRatio = aspectRatio;
	m_projectionMatrix = glm::perspective(glm::radians(m_fov), aspectRatio, m_nearClip, m_farClip);
}

void ViewerCamera::tilt(const float& delta) {
	m_elevation += delta;
	if (m_elevation > 89.0f)
		m_elevation = 89.0f;
	else if (m_elevation < -89.0f)
		m_elevation = -89.0f;
}

void ViewerCamera::move(const glm::vec2& delta) {
	float dx = delta.x;
	float dy = delta.y;
	//Calculate left-right and up down
	float sel = glm::sin(glm::radians(m_elevation));
	float cel = glm::cos(glm::radians(m_elevation));
	float saz = glm::sin(glm::radians(m_azimuth));
	float caz = glm::cos(glm::radians(m_azimuth));
	glm::vec3 target = glm::vec3(-cel * saz, -sel, -cel * caz);
	glm::vec3 up     = glm::vec3(-sel * saz,  cel, -sel * caz);
	glm::vec3 right  = glm::cross(target, up);
	m_origin += dx * right + dy * up;
}