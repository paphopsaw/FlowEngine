#pragma once
#include <vector>
#include "Scene.h"
#include "Shader.h"
#include "Camera.h"

//Should minimize the update of Scene data in here

class Renderer {
public:
	Renderer(Shader& shader)
		:m_shader{ shader } {}
	void draw(Scene& scene, Camera& camera);

private:
	void loadSceneData(Scene& scene);
private:
	Shader m_shader;
	Scene m_scene;
};