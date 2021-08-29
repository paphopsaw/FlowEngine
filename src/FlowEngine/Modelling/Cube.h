#pragma once
#include "Shape.h"

class Cube : public Shape {
public:
	Cube(float length = 1.0f, bool sharedVertices = false);

public:
	float m_length;
	bool m_sharedVertices;
};