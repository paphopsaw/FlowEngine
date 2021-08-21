#define TINYOBJLOADER_IMPLEMENTATION // define this in only *one* .cc
// Optional. define TINYOBJLOADER_USE_MAPBOX_EARCUT gives robust trinagulation. Requires C++11
#define TINYOBJLOADER_USE_MAPBOX_EARCUT
#include "tiny_obj_loader.h"
#include <glad/glad.h>
#include <string>
#include <vector>
#include <iostream>


	//Should I link this to texture?
class Mesh {
public:
	Mesh(std::vector<float>& positions,
			std::vector<float>& normals,
			std::vector<float>& texcoords,
			std::vector<unsigned int>& indices);
	Mesh(std::string& objFilePath, std::string& materialFilesPath);

private:
	unsigned int meshVAO;
	unsigned int positionBO;
	unsigned int normalBO;
	unsigned int texcoordBO;
	unsigned int indexBO;

	unsigned int numVertices;
	unsigned int numIndices;

};