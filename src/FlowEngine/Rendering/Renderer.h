#pragma once
#include <vector>
#include "Scene.h"
#include "Shader.h"
#include "Camera.h"
#include "ResourceManager.h"


//For setting up framebuffer, etc.
//renderer mode (e.g. shadow, wireframe, + custom shaders, etc.) => Depending on shaders



class Renderer {
public:
	Renderer();
	void draw(Shader& shader, Scene& scene, Camera& camera);

private:
	bool shadowMap;
private:
	void drawScene(Shader& shader, Scene& scene);
};