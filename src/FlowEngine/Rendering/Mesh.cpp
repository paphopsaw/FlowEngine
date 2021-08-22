#include "Mesh.h"
#define TINYOBJLOADER_IMPLEMENTATION // define this in only *one* .cc
// Optional. define TINYOBJLOADER_USE_MAPBOX_EARCUT gives robust trinagulation. Requires C++11
//#define TINYOBJLOADER_USE_MAPBOX_EARCUT
#include "tiny_obj_loader.h"

Mesh::Mesh(const std::vector<float>& positions,
	const std::vector<unsigned int>& indices,
	const std::vector<float>& normals,
	const std::vector<float>& texcoords) {
	numIndices = indices.size();
	numVertices = positions.size() / 3;
	//Position buffer
	glGenBuffers(1, &positionBO);
	glBindBuffer(GL_ARRAY_BUFFER, positionBO);
	glBufferData(GL_ARRAY_BUFFER, positions.size() * sizeof(float), positions.data(), GL_STATIC_DRAW);
	//Normal buffer
	if (normals.size() > 0) {
		glGenBuffers(1, &normalBO);
		glBindBuffer(GL_ARRAY_BUFFER, normalBO);
		glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(float), normals.data(), GL_STATIC_DRAW);
	}
	//Texcoord buffer
	if (texcoords.size() > 0) {
		glGenBuffers(1, &texcoordBO);
		glBindBuffer(GL_ARRAY_BUFFER, texcoordBO);
		glBufferData(GL_ARRAY_BUFFER, texcoords.size() * sizeof(float), texcoords.data(), GL_STATIC_DRAW);
	}
	//Index buffer
	glGenBuffers(1, &indexBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
	//Add everything to VAO
	glGenVertexArrays(1, &meshVAO);
	//Position
	glBindVertexArray(meshVAO);
	glBindBuffer(GL_ARRAY_BUFFER, positionBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
	//Normal
	if (normalBO != 0) {
		glBindVertexArray(meshVAO);
		glBindBuffer(GL_ARRAY_BUFFER, normalBO);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glEnableVertexAttribArray(1);
		glBindVertexArray(0);
	}
	//Texcoord
	if (texcoordBO != 0) {
		glBindVertexArray(meshVAO);
		glBindBuffer(GL_ARRAY_BUFFER, texcoordBO);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glEnableVertexAttribArray(2);
		glBindVertexArray(0);
	}
	//Index
	glBindVertexArray(meshVAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBO);
	glBindVertexArray(0);

}

void Mesh::bindVAO() {
	glBindVertexArray(meshVAO);
}

//////////////////////////////////
//TODO: Process mesh
//////////////////////////////////
Mesh::Mesh(std::string& objFilePath, std::string& materialFilesPath) {
	tinyobj::ObjReaderConfig reader_config;
	reader_config.mtl_search_path = materialFilesPath; // Path to material files

	tinyobj::ObjReader reader;

	if (!reader.ParseFromFile(objFilePath, reader_config)) {
		if (!reader.Error().empty()) {
			std::cerr << "TinyObjReader: " << reader.Error();
		}
		exit(1);
	}

	if (!reader.Warning().empty()) {
		std::cout << "TinyObjReader: " << reader.Warning();
	}

	auto& attrib = reader.GetAttrib();
	auto& shapes = reader.GetShapes();
	auto& materials = reader.GetMaterials();

	// Loop over shapes
	for (size_t s = 0; s < shapes.size(); s++) {
		// Loop over faces(polygon)
		size_t index_offset = 0;
		for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) {
			size_t fv = size_t(shapes[s].mesh.num_face_vertices[f]);

			// Loop over vertices in the face.
			for (size_t v = 0; v < fv; v++) {
				// access to vertex
				tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];
				tinyobj::real_t vx = attrib.vertices[3 * size_t(idx.vertex_index) + 0];
				tinyobj::real_t vy = attrib.vertices[3 * size_t(idx.vertex_index) + 1];
				tinyobj::real_t vz = attrib.vertices[3 * size_t(idx.vertex_index) + 2];

				// Check if `normal_index` is zero or positive. negative = no normal data
				if (idx.normal_index >= 0) {
					tinyobj::real_t nx = attrib.normals[3 * size_t(idx.normal_index) + 0];
					tinyobj::real_t ny = attrib.normals[3 * size_t(idx.normal_index) + 1];
					tinyobj::real_t nz = attrib.normals[3 * size_t(idx.normal_index) + 2];
				}

				// Check if `texcoord_index` is zero or positive. negative = no texcoord data
				if (idx.texcoord_index >= 0) {
					tinyobj::real_t tx = attrib.texcoords[2 * size_t(idx.texcoord_index) + 0];
					tinyobj::real_t ty = attrib.texcoords[2 * size_t(idx.texcoord_index) + 1];
				}

				// Optional: vertex colors
				// tinyobj::real_t red   = attrib.colors[3*size_t(idx.vertex_index)+0];
				// tinyobj::real_t green = attrib.colors[3*size_t(idx.vertex_index)+1];
				// tinyobj::real_t blue  = attrib.colors[3*size_t(idx.vertex_index)+2];
			}
			index_offset += fv;

			// per-face material
			shapes[s].mesh.material_ids[f];
		}
	}
}