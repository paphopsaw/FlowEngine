#include "Particle.h"

void Particle::integrate(float dt) {
	if (m_inverseMass <= 0.0f) return;

	std::cout << dt << "\n";
	m_position += m_velocity * dt;
	std::cout << m_position.x << " " << m_position.y << " " << m_position.z << "\n";

	glm::vec3 resultantAcc = m_acceleration;
	m_velocity += resultantAcc * dt;

}

void Particle::clearForce() {
	m_forceAccumulator = glm::vec3(0.0f);
}