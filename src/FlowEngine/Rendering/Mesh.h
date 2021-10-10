#pragma once
#include <glad/glad.h>
#include <string>
#include <vector>
#include <iostream>
#include "Geometries/Geometry.h"


class Mesh {
public:
	Mesh() {}
	Mesh(Geometry shape);
	Mesh(std::string& objFilePath, std::string& materialFilesPath);
	void draw();

private:
	

};