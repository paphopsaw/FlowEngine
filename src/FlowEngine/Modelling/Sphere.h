#pragma once

#include <glm/glm.hpp>
#include "Shape.h"
#include <iostream>

class Sphere : public Shape {
public:
	Sphere(float radius = 1.0f, unsigned int numLatitudes = 18, unsigned int numLongitudes = 36);
	void clear();
	void setLatLong(unsigned int numLatitudes, unsigned int numLongitudes);
private:
	float m_radius;
	unsigned int m_numLatitudes;
	unsigned int m_numLongitudes;
};