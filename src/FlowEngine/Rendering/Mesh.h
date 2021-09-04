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
	~Mesh();
	void bindVAO();
	unsigned int getNumVertices() { return numVertices; }
	unsigned int getNumIndices() { return numIndices; }

private:
	unsigned int meshVAO;
	unsigned int positionBO;
	unsigned int normalBO;
	unsigned int texcoordBO;
	unsigned int indexBO;

	unsigned int numVertices;
	unsigned int numIndices;

};