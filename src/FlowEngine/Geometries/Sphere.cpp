#include "Sphere.h"

Sphere::Sphere(float radius, unsigned int numLatitudes, unsigned int numLongitudes)
	:m_radius{ radius }, m_numLatitudes{ numLatitudes }, m_numLongitudes{ numLongitudes } {
	setLatLong(numLatitudes, numLongitudes);
}

void Sphere::clear() {
	m_positions.clear();
	m_normals.clear();
	m_indices.clear();
	m_texcoords.clear();
	m_numVertices = 0;
	m_numIndices = 0;
	m_radius = 1.0f;
	m_numLatitudes = 0;
	m_numLongitudes = 0;
}

//TODO: Consider separate VERTICES & INDICES into 2 functions.
//TODO: Unshare texcoord at poles
void Sphere::setLatLong(unsigned int numLatitudes, unsigned int numLongitudes) {
	clear();
	m_numLatitudes  = numLatitudes;
	m_numLongitudes = numLongitudes;

	//VERTICES
	//There are 2 points at the poles
	m_numVertices = 2 + m_numLatitudes * m_numLongitudes;
	float dLatitude = 180.0f / (m_numLatitudes + 1);
	float dLongitude = 360.0f / m_numLongitudes;
	//Add north pole
	m_positions.push_back(0.0f);	//x
	m_positions.push_back(1.0f);	//y
	m_positions.push_back(0.0f);	//z
	m_normals.push_back(0.0f);		//x
	m_normals.push_back(1.0f);		//y
	m_normals.push_back(0.0f);		//z
	for (unsigned int i = 1; i < m_numLatitudes + 1; i++) {
		float elevation = 90.0f - dLatitude * i;
		for (unsigned int j = 0; j < m_numLongitudes; j++) {
			float azimuth = dLongitude * j;
			float sel = glm::sin(glm::radians(elevation));
			float cel = glm::cos(glm::radians(elevation));
			float saz = glm::sin(glm::radians(azimuth));
			float caz = glm::cos(glm::radians(azimuth));

			m_positions.push_back(cel * saz);	//x
			m_positions.push_back(sel);			//y
			m_positions.push_back(cel * caz);	//z
			m_normals.push_back(cel * saz);		//x
			m_normals.push_back(sel);			//y
			m_normals.push_back(cel * caz);		//z
		}
	}
	//Add south pole
	m_positions.push_back(0.0f);	//x
	m_positions.push_back(-1.0f);	//y
	m_positions.push_back(0.0f);	//z
	m_normals.push_back(0.0f);		//x
	m_normals.push_back(-1.0f);		//y
	m_normals.push_back(0.0f);		//z

	//INDICES
	m_numIndices = 3 * (2 * m_numLatitudes * m_numLongitudes + 2);
	//Around north pole
	for (unsigned int j = 0; j < m_numLongitudes; j++) {
		m_indices.push_back(0);
		m_indices.push_back(j + 1);
		m_indices.push_back(j + 2);
	}
	m_indices.push_back(0);
	m_indices.push_back(m_numLongitudes);
	m_indices.push_back(1);

	//In the middle
	for (unsigned int i = 0; i < m_numLatitudes - 1; i++) {
		for (unsigned int j = 0; j < m_numLongitudes - 1; j++) {
			m_indices.push_back(i * m_numLongitudes + j + 1);
			m_indices.push_back((i + 1) * m_numLongitudes + j + 1);
			m_indices.push_back((i + 1) * m_numLongitudes + j + 2);
			m_indices.push_back(i * m_numLongitudes + j + 1);
			m_indices.push_back((i + 1) * m_numLongitudes + j + 2);
			m_indices.push_back(i * m_numLongitudes + j + 2);
		}
		m_indices.push_back(i * m_numLongitudes + m_numLongitudes);
		m_indices.push_back((i + 1) * m_numLongitudes + m_numLongitudes);
		m_indices.push_back((i + 1) * m_numLongitudes + 1);
		m_indices.push_back(i * m_numLongitudes + m_numLongitudes);
		m_indices.push_back((i + 1) * m_numLongitudes + 1);
		m_indices.push_back(i * m_numLongitudes + 1);
	}

	//Around south pole
	for (unsigned int j = 0; j < m_numLongitudes; j++) {
		m_indices.push_back((m_numLatitudes - 1) * m_numLongitudes + j + 1);
		m_indices.push_back(m_numLatitudes * m_numLongitudes + 1);			//South pole
		m_indices.push_back((m_numLatitudes - 1) * m_numLongitudes +  j + 2);
	}
	m_indices.push_back((m_numLatitudes - 1) * m_numLongitudes + m_numLongitudes);
	m_indices.push_back(m_numLatitudes * m_numLongitudes + 1);			//South pole
	m_indices.push_back((m_numLatitudes - 1) * m_numLongitudes + 1);



}