#pragma once
#include <glad/glad.h>
#include <vector>

//Generate primitive shapes like cubes, spheres, tetrahedrons, etc.
class Geometry { 
public:
	Geometry() {}
	std::vector<float>& getPositions() { return m_positions; }
	std::vector<unsigned int>& getIndices() { return m_indices; }
	std::vector<float>& getNormals() { return m_normals; }
	std::vector<float>& getTexcoords() { return m_texcoords; }
	unsigned int getNumVertices() const { return m_numVertices; }
	unsigned int getNumIndices() const { return m_numIndices; }
	void bindVAO() const;
	void unbindVAO() const;
	void draw() const;
	void clear();

protected:
	std::vector<float> m_positions;
	std::vector<unsigned int> m_indices;
	std::vector<float> m_normals;
	std::vector<float> m_texcoords;

	unsigned int VAO;
	unsigned int positionBO;
	unsigned int normalBO;
	unsigned int texcoordBO;
	unsigned int indexBO;

	unsigned int m_numVertices;
	unsigned int m_numIndices;

protected:
	void loadToGPU();


};