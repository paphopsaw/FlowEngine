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
	shader.setInt("numDirLights", static_cast<int>(scene.getDirLights().size()));
	shader.setInt("numPointLights", static_cast<int>(scene.getPointLights().size()));
	//TODO : Create array of lights in shader
	int i = 0;
	for (auto dirLight : scene.getDirLights()) {
		if (dirLight.second.isOn) {
			std::string varName{ "dirLights[" + std::to_string(i) + "]." };
			shader.setVec3((varName + "direction").c_str(), dirLight.second.direction);
			shader.setVec3((varName + "ambient").c_str(), dirLight.second.ambient);
			shader.setVec3((varName + "diffuse").c_str(), dirLight.second.diffuse);
			shader.setVec3((varName + "specular").c_str(), dirLight.second.specular);
			++i;
		}
	}
	//TODO : Point light; need to have an option for rendering the light itself or not??
	i = 0;
	for (auto pointLight : scene.getPointLights()) {
		std::string varName{ "pointLights[" + std::to_string(i) + "]." };
		shader.setVec3((varName + "position").c_str(), pointLight.second.position);
		shader.setVec3((varName + "ambient").c_str(), pointLight.second.ambient);
		shader.setVec3((varName + "diffuse").c_str(), pointLight.second.diffuse);
		shader.setVec3((varName + "specular").c_str(), pointLight.second.specular);
		shader.setFloat((varName + "constant").c_str(), pointLight.second.constant);
		shader.setFloat((varName + "linear").c_str(), pointLight.second.linear);
		shader.setFloat((varName + "quadratic").c_str(), pointLight.second.quadratic);
		++i;
	}

	//Load instances data to GPU and draw
	for (auto instance : scene.getInstances()) {
		//Get model matrix from transform
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, instance.second.transform.translation);
		model = glm::mat4_cast(instance.second.transform.rotation) * model;
		model = glm::scale(model, instance.second.transform.scale);
		shader.setMat4("model", model);
		//Material
		shader.setFloat("material.shininess", instance.second.material.shininess);
		shader.setVec3("material.color", instance.second.material.color);


		Mesh mesh = ResourceManager::getMesh(instance.second.meshName);
		mesh.draw();
	}
}