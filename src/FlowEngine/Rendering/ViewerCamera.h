#pragma once
#include <glm/glm.hpp>
#include "Camera.h"

class ViewerCamera : public Camera {
public:
	ViewerCamera() = default;
	ViewerCamera(float fov, float aspectRatio, float nearClip, float farClip) 
		: m_fov{ fov }, m_aspectRatio{ aspectRatio }, m_nearClip{ nearClip }, m_farClip{ farClip },
		Camera(glm::perspective(glm::radians(fov), aspectRatio, nearClip, farClip)) {}\

	const glm::mat4 getViewMatrix() const;

	glm::vec3 getOrigin() { return m_origin; }
	float getZoom() { return m_zoom; }
	float getDeclination() { return m_declination; }
	float getAzimuth() { return m_azimuth; }

	void setAspectRatio(float aspectRatio);
	void zoom(const float& delta) { m_zoom += delta; }
	void rotate(const float& delta) { m_azimuth += delta; }
	void tilt(const float& delta);
	void move(const glm::vec2& delta);

private:
	float m_fov = 45.0f;
	float m_aspectRatio = 1.778f;
	float m_nearClip = 0.1f;
	float m_farClip = 1000.0f;
	glm::vec3 m_origin = glm::vec3(0.0f, 0.0f, 0.0f);
	float m_zoom = -5.0f;
	float m_declination = 0.0f;
	float m_azimuth = 0;
};