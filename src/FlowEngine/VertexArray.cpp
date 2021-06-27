#include "VertexArray.h"

VertexArray::VertexArray() {
	glGenVertexArrays(1, &id);
}

VertexArray::~VertexArray() {
	glDeleteVertexArrays(1, &id);
}

void VertexArray::bind() const {
	glBindVertexArray(id);
}

void VertexArray::unbind() const {
	glBindVertexArray(0);
}

void VertexArray::addVertexBuffer(const VertexBuffer& vertexBuffer) {
	glBindVertexArray(id);
	vertexBuffer.bind();
	const auto& layout{ vertexBuffer.getLayout() };
	unsigned int stride{ vertexBuffer.getStride() };
	unsigned int offset{ 0 };
	for (const auto& elementLength : layout) {
		glEnableVertexAttribArray(bufferIndex);
		glVertexAttribPointer(bufferIndex, 
							  elementLength, 
			                  GL_FLOAT,
							  GL_FALSE,
							  stride,
							  (const void*)(offset * sizeof(float)));
		offset += elementLength;
		++bufferIndex;
	}
	
}

void VertexArray::setIndexBuffer(const IndexBuffer& indexBuffer) {
	glBindVertexArray(id);
	indexBuffer.bind();
}