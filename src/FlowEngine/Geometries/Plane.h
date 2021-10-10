#pragma once
#include "Geometry.h"

//TODO: Create segments and customizable length
class Plane : public Geometry {
public:
	Plane();
private:
	float m_length;
};