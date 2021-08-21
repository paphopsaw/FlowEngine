#include "Mesh.h"

Mesh::Mesh(std::vector<float>& positions,
		std::vector<float>& normals,
		std::vector<float>& texcoords,
		std::vector<unsigned int>& indices) {
	numIndices = indices.size();
	numVertices = positions.size() / 3;
	//Position buffer
	glGenBuffers(1, &positionBO);
	glBindBuffer(GL_ARRAY_BUFFER, positionBO);
	glBufferData(GL_ARRAY_BUFFER, positions.size() * sizeof(float), positions.data(), GL_STATIC_DRAW);
	//Normal buffer
	glGenBuffers(1, &normalBO);
	glBindBuffer(GL_ARRAY_BUFFER, normalBO);
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(float), normals.data(), GL_STATIC_DRAW);
	//Texcoord buffer
	glGenBuffers(1, &texcoordBO);
	glBindBuffer(GL_ARRAY_BUFFER, texcoordBO);
	glBufferData(GL_ARRAY_BUFFER, texcoords.size() * sizeof(float), texcoords.data(), GL_STATIC_DRAW);
	//Index buffer
	glGenBuffers(1, &indexBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
	//Add everything to VAO
	glGenVertexArrays(1, &meshVAO);
	//Position
	glBindVertexArray(meshVAO);
	glBindBuffer(GL_ARRAY_BUFFER, positionBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
	//Normal
	glBindVertexArray(meshVAO);
	glBindBuffer(GL_ARRAY_BUFFER, normalBO);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glEnableVertexAttribArray(1);
	glBindVertexArray(0);
	//Texcoord
	glBindVertexArray(meshVAO);
	glBindBuffer(GL_ARRAY_BUFFER, texcoordBO);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glEnableVertexAttribArray(2);
	glBindVertexArray(0);
	//Index
	glBindVertexArray(meshVAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBO);
	glBindVertexArray(0);

}

Mesh::Mesh(std::string& objFilePath, std::string& materialFilesPath) {

}