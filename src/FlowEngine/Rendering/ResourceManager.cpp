#include "ResourceManager.h"


std::map<std::string, Shader>       ResourceManager::s_shaders;
std::map<std::string, Texture2D>    ResourceManager::s_textures;

Shader ResourceManager::loadShader(const char* vertexPath, const char* fragmentPath, std::string name) {
	Shader shader(vertexPath, fragmentPath);
	s_shaders[name] = shader;
	return shader;
}

Shader ResourceManager::getShader(std::string name) {
	return s_shaders[name];
}

Texture2D ResourceManager::loadTexture(const char* texturePath, bool alpha, std::string name) {
	unsigned int format{ GL_RGB };
	if (alpha)
		format = GL_RGBA;
	Texture2D texture2d(texturePath, format);
	s_textures[name] = texture2d;
	return texture2d;
}

Texture2D ResourceManager::getTexture(std::string name) {
	return s_textures[name];
}


void ResourceManager::clear() {
	for (auto i : s_shaders) {
		glDeleteProgram(i.second.ID);
		s_shaders.erase(i.first);
	}
	for (auto i : s_textures) {
		glDeleteTextures(1, &i.second.ID);
		s_textures.erase(i.first);
	}
	for (auto i : s_geometries) {
		i.second.clear();
		s_geometries.erase(i.first);
	}
}