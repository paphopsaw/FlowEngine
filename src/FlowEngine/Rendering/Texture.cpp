#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture2D::Texture2D()
	: width{ 0 }, height{ 0 }, nrChannels{ 3 }, 
	wrap_s{ GL_REPEAT }, wrap_t{ GL_REPEAT }, min_filter{ GL_LINEAR_MIPMAP_LINEAR }, max_filter{ GL_LINEAR }
{
	glGenTextures(1, &this->ID);
}

Texture2D::Texture2D(const char* filePath, unsigned int format)
	: wrap_s{ GL_REPEAT }, wrap_t{ GL_REPEAT }, min_filter{ GL_LINEAR_MIPMAP_LINEAR }, max_filter{ GL_LINEAR }
{

	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, ID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap_s);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap_t);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, min_filter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, max_filter);

	stbi_set_flip_vertically_on_load(true);
	data = stbi_load(filePath, &width, &height, &nrChannels, 0);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "Failed to load texture" << std::endl;
	}
	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(data);
}

Texture2D::~Texture2D() {
	glDeleteTextures(1, &ID);
}

void Texture2D::bind(unsigned int slot) {
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture2D::unbind() {
	glBindTexture(GL_TEXTURE_2D, 0);
}