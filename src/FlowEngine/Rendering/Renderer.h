#pragma once
#include <vector>
#include "Scene.h"
#include "Shader.h"

class Renderer {
public:
	Renderer(Shader& shader)
		:m_shader{ shader } {}
	~Renderer();
	void draw(Scene& scene);
private:
	Shader m_shader
};