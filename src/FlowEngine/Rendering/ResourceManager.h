#pragma once
#include <map>
#include <string>
#include <glad/glad.h>
#include "Texture.h"
#include "Shader.h"
#include "Mesh.h"
#include "Geometries/Geometry.h"

// For managing resources that are loaded from files
// TODO: Delete resources
class ResourceManager {
public:
	static std::map<std::string, Shader> s_shaders;
	static std::map<std::string, Texture2D> s_textures;
	static std::map<std::string, Geometry> s_geometries;
	static Shader loadShader(const char* vertexPath, const char* fragmentPath, std::string name);
	static Shader getShader(std::string name);
	static Texture2D loadTexture(const char* texturePath, bool alpha, std::string name);
	static Texture2D getTexture(std::string name);
	static void clear();

private:
	ResourceManager() {}
};