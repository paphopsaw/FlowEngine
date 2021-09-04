#include "Square.h"

Square::Square(float length)
	:m_length{ length } {
	m_numVertices = 4;
	m_numIndices = 6;
	m_positions = {
		-0.5f, 0.0f,  0.5f,
		 0.5f, 0.0f,  0.5f,
		 0.5f, 0.0f, -0.5f,
		-0.5f, 0.0f, -0.5f
	};
	m_indices = {
		0, 1, 2,
		0, 2, 3
	};
	m_normals = {
		0.0f, 1.0f,  0.0f,
		0.0f, 1.0f,  0.0f,
		0.0f, 1.0f,  0.0f,
		0.0f, 1.0f,  0.0f,
	};
	m_texcoords = {
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f
	};
}