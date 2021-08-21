#pragma once
#include <vector>
#include <map>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include "ResourceManager.h"


/*
 Instance [(InstanceID, Mesh, Transform), ...]
 Light
*/

struct Instance {
	std::string meshName;
	Transform transform;
};


struct Transform {
	glm::vec3 scale;
	glm::quat rotation;
	glm::vec3 translation;
};


class Scene {
public:
	Scene() {}
	~Scene();
	void addInstance(std::string meshName, Transform transform, std::string name);

private:
	std::map<std::string, Instance> m_instances;
	Camera m_camera;
};