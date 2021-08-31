#pragma once
#include "Shape.h"

class Square : public Shape {
public:
	Square(float length = 1.0f);
private:
	float m_length;
};