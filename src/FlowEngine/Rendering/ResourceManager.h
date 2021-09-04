#pragma once
#include <map>
#include <string>
#include <glad/glad.h>
#include "Texture.h"
#include "Shader.h"
#include "Mesh.h"
#include "Modelling/Shape.h"

class ResourceManager {
public:
	static std::map<std::string, Shader> s_shaders;
	static std::map<std::string, Texture2D> s_textures;
	static std::map<std::string, Mesh> s_meshes;
	static Shader loadShader(const char* vertexPath, const char* fragmentPath, std::string name);
	static Shader getShader(std::string name);
	static Texture2D loadTexture(const char* texturePath, bool alpha, std::string name);
	static Texture2D getTexture(std::string name);
	static Mesh loadMesh(Shape shape, std::string name);
	static Mesh getMesh(std::string name);
	static void clear();

private:
	ResourceManager() {}
};