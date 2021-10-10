#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <string>
#include <vector>
#include <iostream>
#include "Geometries/Geometry.h"


struct Transform {
	glm::vec3 scale;
	glm::quat rotation;
	glm::vec3 position;
};

//Opacity, transparency, wireframe, etc.
struct Material {
	float shininess;
	glm::vec3 color;
};

class Mesh {
public:
	Mesh(const Geometry& geometry, Material material);
	void draw();
	void setScale(glm::vec3 scale) { m_transform.scale = scale; }
	void setRotation(glm::quat rotation) { m_transform.rotation = rotation; }
	void setPosition(glm::vec3 position) { m_transform.position = position; }

	glm::vec3 getScale() { return m_transform.scale; }
	glm::quat getRotation() { return m_transform.rotation; }
	glm::vec3 getPosition() { return m_transform.position; }


private:
	const Geometry& m_geometry;
	Material m_material;
	Transform m_transform;
};