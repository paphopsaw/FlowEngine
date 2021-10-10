#pragma once
#include <vector>
#include <map>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include "ResourceManager.h"


struct Transform {
	glm::vec3 scale;
	glm::quat rotation;
	glm::vec3 translation;
};

struct Material {
	float shininess;
	glm::vec3 color;
};

struct DirectionalLight {
	glm::vec3 direction;
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
	bool isOn;
};

struct PointLight {
	glm::vec3 position;
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
	float constant;
	float linear;
	float quadratic;
	bool isOn;
};

struct Instance {
	std::string meshName;
	Transform transform;
	Material material;
};

class Scene {
public:
	Scene() {}
	~Scene() = default;
	void addInstance(std::string meshName, Transform transform, Material material, std::string name);
	void removeInstance(std::string name);
	void clearInstances();
	std::map<std::string, Instance>& getInstances() { return m_instances; }
	//Load scene from file?
	void addDirectionalLight(DirectionalLight light, std::string name);
	void removeDirectionalLight(std::string name);
	void setDirectionalLightIsOn(bool isOn, std::string name);
	std::map<std::string, DirectionalLight>& getDirLights() { return m_dirLights; }
	void addPointLight(PointLight light, std::string name);
	void removePointLight(std::string name);
	void setPointLightIsOn(bool isOn, std::string name);
	std::map<std::string, PointLight>& getPointLights() { return m_pointLights; }

private:
	std::map<std::string, Instance> m_instances;
	std::map<std::string, DirectionalLight> m_dirLights;
	std::map<std::string, PointLight> m_pointLights;
};