#pragma once
#include <glad/glad.h>
#include <string>
#include <vector>
#include <iostream>


	//Should I link this to texture?
class Mesh {
public:
	Mesh(const std::vector<float>& positions,
			const std::vector<unsigned int>& indices,
			const std::vector<float>& normals = std::vector<float>(),
			const std::vector<float>& texcoords = std::vector<float>());
	//TODO: Constructor from Shape
	Mesh(std::string& objFilePath, std::string& materialFilesPath);
	void bindVAO();

private:
	unsigned int meshVAO;
	unsigned int positionBO;
	unsigned int normalBO;
	unsigned int texcoordBO;
	unsigned int indexBO;

	unsigned int numVertices;
	unsigned int numIndices;

};