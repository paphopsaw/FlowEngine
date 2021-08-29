#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Camera.h"
#include <iostream>

class ViewerCamera : public Camera {
public:
	ViewerCamera(float fov = 45.0f, float aspectRatio = 1.778f, float nearClip = 0.1f, float farClip = 1000.0f)
		: m_fov{ fov }
		, m_aspectRatio{ aspectRatio }
		, m_nearClip{ nearClip }
		, m_farClip{ farClip }
		, Camera(glm::perspective(glm::radians(fov), aspectRatio, nearClip, farClip)) {}

	const glm::mat4 getViewMatrix() const;

	glm::vec3 getOrigin() { return m_origin; }
	float getDistance() { return m_distance; }
	float getElevation() { return m_elevation; }
	float getAzimuth() { return m_azimuth; }

	void setAspectRatio(float aspectRatio);
	void zoom(const float& delta) { m_distance += delta; }
	void rotate(const float& delta) { m_azimuth -= delta; }
	void tilt(const float& delta);
	void move(const glm::vec2& delta);

private:
	//projection
	float m_fov;
	float m_aspectRatio;
	float m_nearClip;
	float m_farClip;
	//view
	glm::vec3 m_origin = glm::vec3(0.0f, 0.0f, 0.0f);
	float m_distance = 5.0f;
	float m_elevation = 0.0f;
	float m_azimuth = 0.0f;
};