#include "Buffer.h"

VertexBuffer::VertexBuffer(std::vector<float>& vertices) {
	glCreateBuffers(1, &id);
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer() {
	glDeleteBuffers(1, &id);
}

void VertexBuffer::bind() const {
	glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VertexBuffer::unbind() const {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

unsigned int VertexBuffer::getStride() const {
	unsigned int sum{ 0 };
	for (auto i : layout) {
		sum += i;
	}
	return sum * sizeof(float);
}


IndexBuffer::IndexBuffer(std::vector<unsigned int>& indices) {
	glCreateBuffers(1, &id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer() {
	glDeleteBuffers(1, &id);
}

void IndexBuffer::bind() const {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void IndexBuffer::unbind() const {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}