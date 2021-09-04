#pragma once
#include <glm/glm.hpp>

class Camera {
public:
	Camera(glm::mat4 projectionMatrix)
		: m_projectionMatrix{ projectionMatrix } {}
	const glm::mat4& getProjectionMatrix() const { return m_projectionMatrix; }
	virtual const glm::mat4 getViewMatrix() const = 0;
	virtual glm::vec3 getPositions() = 0;

protected:
	glm::mat4 m_projectionMatrix;
};