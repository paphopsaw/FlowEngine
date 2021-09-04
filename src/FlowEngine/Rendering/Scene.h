#pragma once
#include <vector>
#include <map>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include "ResourceManager.h"
#include "Camera.h"


/*
 Instance [(InstanceID, Mesh, Transform), ...]
 Light
*/


struct Transform {
	glm::vec3 scale;
	glm::quat rotation;
	glm::vec3 translation;
};

struct Material {
	float shininess;
	glm::vec4 color;
};

struct DirectionalLight {
	glm::vec3 direction;
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
};

struct PointLight {
	glm::vec3 position;
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
	float constant;
	float linear;
	float quadratic;
};

struct Instance {
	std::string meshName;
	Transform transform;
	Material material;
};



class Scene {
public:
	Scene() {}
	~Scene();
	void addInstance(std::string meshName, Transform transform, std::string name);
	void removeInstance(std::string name);
	void addCamera(Camera camera, std::string name);
	void removeCamera(std::string name);
	void addDirectionalLight(DirectionalLight light, std::string name);
	void removeDirectionalLight(std::string name);


private:
	std::map<std::string, Instance> m_instances;
	std::map<std::string, Camera> m_cameras;
	std::map<std::string, DirectionalLight> m_dirLight;
	std::map<std::string, PointLight> m_pointLight;
};