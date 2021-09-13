#pragma once
#include <glad/glad.h>
#include <string>
#include <vector>
#include <iostream>
#include "Modelling/Shape.h"


class Mesh {
public:
	Mesh() {}
	Mesh(const std::vector<float>& positions,
			const std::vector<unsigned int>& indices,
			const std::vector<float>& normals = std::vector<float>(),
			const std::vector<float>& texcoords = std::vector<float>());
	Mesh(Shape shape);
	Mesh(std::string& objFilePath, std::string& materialFilesPath);
	void draw();
	unsigned int getNumVertices() { return m_numVertices; }
	unsigned int getNumIndices() { return m_numIndices; }
	void bindVAO();
	void unbindVAO();
	void clear();

private:
	unsigned int meshVAO;
	unsigned int positionBO;
	unsigned int normalBO;
	unsigned int texcoordBO;
	unsigned int indexBO;

	unsigned int m_numVertices;
	unsigned int m_numIndices;

};