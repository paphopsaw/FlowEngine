#include "Renderer.h"

Renderer::Renderer() {
	glEnable(GL_DEPTH_TEST);
}

void Renderer::draw(Shader& shader, Scene& scene, Camera& camera) {
	shader.bind();
	//Load camera data
	glm::mat4 proj = camera.getProjectionMatrix();
	shader.setMat4("projection", proj);
	glm::mat4 view = camera.getViewMatrix();
	shader.setMat4("view", view);
	glm::vec3 viewPosition = camera.getPositions();
	shader.setVec3("viewPos", viewPosition);
	//Load scene data
	drawScene(shader, scene);

}

void Renderer::drawScene(Shader& shader, Scene& scene) {
	//Load light to GPU
	for (auto dirLight : scene.getDirLights()) {
		shader.setVec3("dirLight.ambient", dirLight.second.ambient);
		shader.setVec3("dirLight.diffuse", dirLight.second.diffuse);
		shader.setVec3("dirLight.specular", dirLight.second.specular);
		shader.setVec3("dirLight.direction", dirLight.second.direction);
	}
	//Load instances data to GPU and draw
	for (auto instance : scene.getInstances()) {
		//Get model matrix from transform
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::mat4_cast(instance.second.transform.rotation) * model;
		model = glm::scale(model, instance.second.transform.scale);
		model = glm::translate(model, instance.second.transform.translation);
		shader.setMat4("model", model);
		//Material
		shader.setFloat("material.shininess", instance.second.material.shininess);
		shader.setVec4("material.color", instance.second.material.color);


		Mesh mesh = ResourceManager::getMesh(instance.second.meshName);
		mesh.draw();
	}
}