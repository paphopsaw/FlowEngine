#pragma once
#include <vector>
#include "Scene.h"
#include "Shader.h"
#include "Camera.h"
#include "ResourceManager.h"


//For setting up framebuffer, etc.
class Renderer {
public:
	Renderer();
	void draw(Shader& shader, Scene& scene, Camera& camera);

private:
	void drawScene(Shader& shader, Scene& scene);
};