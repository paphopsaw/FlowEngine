#pragma once
#include <glad/glad.h>
#include <vector>

class VertexBuffer {
public:
	VertexBuffer(std::vector<float>& vertices);
	~VertexBuffer();

	void bind() const;
	void unbind() const;
	void setLayout(const std::vector<unsigned int>& layout) { this->layout = layout; }
	const std::vector<unsigned int>& getLayout() const { return layout; }
	unsigned int getStride() const;

private:
	unsigned int id;
	//e.g. [3,3,2]
	std::vector<unsigned int> layout;
};

class IndexBuffer {
public:
	IndexBuffer(std::vector<unsigned int>& indices);
	~IndexBuffer();

	void bind() const;
	void unbind() const;

private:
	unsigned int id;
};