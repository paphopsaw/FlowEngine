#pragma once
#include <vector>

//Generate primitive shapes like cubes, spheres, tetrahedrons, etc.
class Shape {
public:
	std::vector<float>& getPositions() { return m_positions; }
	std::vector<unsigned int>& getIndices() { return m_indices; }
	std::vector<float>& getNormals() { return m_normals; }
	std::vector<float>& getTexcoords() { return m_texcoords; }
	unsigned int getNumVertices() { return m_numVertices; }
	unsigned int getNumIndices() { return m_numIndices; }
protected:
	Shape() {}
protected:
	std::vector<float> m_positions;
	std::vector<unsigned int> m_indices;
	std::vector<float> m_normals;
	std::vector<float> m_texcoords;
	unsigned int m_numVertices;
	unsigned int m_numIndices;

};