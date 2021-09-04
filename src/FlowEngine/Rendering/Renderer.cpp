#include "Renderer.h"


void Renderer::draw(Scene& scene, Camera& camera) {
	m_shader.bind();
	//Load camera data
	glm::mat4 proj = camera.getProjectionMatrix();
	m_shader.setMat4("projection", proj);
	glm::mat4 view = camera.getViewMatrix();
	m_shader.setMat4("view", view);
	glm::vec3 viewPosition = camera.getPositions();
	m_shader.setVec3("viewPos", viewPosition);
	//Load scene data
	loadSceneData(scene);

}

void Renderer::loadSceneData(Scene&) {

}