#pragma once

#include <glad/glad.h>
#include "Buffer.h"
#include <vector>
#include <iostream>

class VertexArray {
public:
	VertexArray();
	~VertexArray();

	void bind() const;
	void unbind() const;
	void addVertexBuffer(const VertexBuffer& vertexBuffer);
	void setIndexBuffer(const IndexBuffer& vertexBuffer);

private:
	unsigned int id;
	unsigned int bufferIndex{ 0 };
};