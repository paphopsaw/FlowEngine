#include "Geometry.h"

Geometry::loadToGPU() {
	//Position buffer
	glGenBuffers(1, &positionBO);
	glBindBuffer(GL_ARRAY_BUFFER, positionBO);
	glBufferData(GL_ARRAY_BUFFER, m_positions.size() * sizeof(float), m_positions.data(), GL_STATIC_DRAW);
	//Normal buffer
	glGenBuffers(1, &normalBO);
	glBindBuffer(GL_ARRAY_BUFFER, normalBO);
	glBufferData(GL_ARRAY_BUFFER, m_normals.size() * sizeof(float), m_normals.data(), GL_STATIC_DRAW);
	//Texcoord buffer
	glGenBuffers(1, &texcoordBO);
	glBindBuffer(GL_ARRAY_BUFFER, texcoordBO);
	glBufferData(GL_ARRAY_BUFFER, m_texcoords.size() * sizeof(float), m_texcoords.data(), GL_STATIC_DRAW);
	//Index buffer
	glGenBuffers(1, &indexBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(unsigned int), m_indices.data(), GL_STATIC_DRAW);
	//Add everything to VAO
	glGenVertexArrays(1, &VAO);
	//Position
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, positionBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
	//Normal
	if (normalBO != 0) {
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, normalBO);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glEnableVertexAttribArray(1);
		glBindVertexArray(0);
	}
	//Texcoord
	if (texcoordBO != 0) {
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, texcoordBO);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glEnableVertexAttribArray(2);
		glBindVertexArray(0);
	}
	//Index
	glBindVertexArray(VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBO);
	glBindVertexArray(0);
}

void Geometry::bindVAO() {
	glBindVertexArray(VAO);
}

void Geometry::unbindVAO() {
	glBindVertexArray(0);
}

void Geometry::draw() {
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, m_numIndices, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}