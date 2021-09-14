#include "Scene.h"

void Scene::addInstance(std::string meshName, Transform transform, Material material, std::string name) {
	Instance instance{
		meshName,
		transform,
		material
	};
	m_instances[name] = instance;
}

void Scene::removeInstance(std::string name) {
	m_instances.erase(name);
}

void Scene::clearInstances() {
	m_instances.clear();
}

void Scene::addDirectionalLight(DirectionalLight light, std::string name) {
	m_dirLights[name] = light;
}

void Scene::removeDirectionalLight(std::string name) {
	m_dirLights.erase(name);
}

void Scene::setDirectionalLightIsOn(bool isOn, std::string name) {
	m_dirLights[name].isOn = isOn;
}

void Scene::addPointLight(PointLight light, std::string name) {
	m_pointLights[name] = light;
}

void Scene::removePointLight(std::string name) {
	m_pointLights.erase(name);
}

void Scene::setPointLightIsOn(bool isOn, std::string name) {
	m_pointLights[name].isOn = isOn;
}