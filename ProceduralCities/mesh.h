#ifndef MESH_H_INCLUDED
#define MESH_H_INCLUDED

// https://github.com/Hopson97/MineCraft-One-Week-Challenge/blob/master/Source/Mesh.h 28.01.20

#include "glad/glad.h"
#include <vector>

struct Mesh {
	std::vector<GLfloat> vertexPositions;
	std::vector<GLfloat> textureCoords;
	std::vector<GLuint> indices;
};

#endif // MESH_H_INCLUDED