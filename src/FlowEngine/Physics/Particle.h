#pragma once
#include <glm/glm.hpp>
#include <iostream>

class Particle {
public:
	Particle() {}
	Particle(float mass, glm::vec3 position)
		: m_inverseMass{ 1 / mass }, 
		  m_position { position } {}
	Particle(float mass, glm::vec3 position, glm::vec3 velocity)
		: m_inverseMass{ 1 / mass }, 
		  m_position{ position }, 
		  m_velocity{ velocity } {}

	void setAcceleration(glm::vec3 acc) { m_acceleration = acc; }
	void addForce(glm::vec3 force) { m_forceAccumulator += force; }
	void integrate(float dt);
	glm::vec3 getPosition() { return m_position; }


protected:
	void clearForce();

protected:
	glm::vec3 m_position = glm::vec3(0.0f);
	glm::vec3 m_velocity = glm::vec3(0.0f);
	glm::vec3 m_acceleration = glm::vec3(0.0f);
	glm::vec3 m_forceAccumulator = glm::vec3(0.0f);

	float m_damping;
	float m_inverseMass;
};