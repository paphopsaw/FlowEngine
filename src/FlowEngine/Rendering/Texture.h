#pragma once
#include <iostream>
#include <glad/glad.h>


class Texture2D {
private:
	unsigned char* data;
	int width;
	int height;
	int nrChannels;
	unsigned int wrap_s;
	unsigned int wrap_t;
	unsigned int min_filter;
	unsigned int max_filter;

public:
	Texture2D();
	Texture2D(const char* filePath, unsigned int format);
	~Texture2D();
	void bind(unsigned int slot);
	void unbind();
	unsigned int ID;
};
