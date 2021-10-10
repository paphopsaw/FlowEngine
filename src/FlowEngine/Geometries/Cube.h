#pragma once
#include "Geometry.h"

class Cube : public Geometry {
public:
	Cube(float length = 1.0f, bool sharedVertices = false);

public:
	float m_length;
	bool m_sharedVertices;
};