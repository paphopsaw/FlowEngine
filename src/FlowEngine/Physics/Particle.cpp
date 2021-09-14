#include "Particle.h"

void Particle::integrate(float dt) {
	if (m_inverseMass <= 0.0f) return;


	//Update position
	m_position += m_velocity * dt;

	//Update velocity
	glm::vec3 resultantAcc = m_acceleration;
	m_velocity += resultantAcc * dt;

}

void Particle::clearForce() {
	m_forceAccumulator = glm::vec3(0.0f);
}