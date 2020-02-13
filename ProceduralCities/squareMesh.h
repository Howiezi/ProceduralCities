#ifndef SQUAREMESH_H_INCLUDED
#define SQAUREMESH_H_INCLUDED

#include "model.h"

Mesh createSquare(int size);
Model getSquareModel(int size);
void addSquareModelLess(int size, Renderer *renderer);

Mesh createSquare(int size) {
	Mesh mesh;
	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			mesh.vertexPositions.push_back(x*0.1f);
			mesh.vertexPositions.push_back(y*0.1f);
			mesh.vertexPositions.push_back(0);

			mesh.vertexPositions.push_back(x * 0.1f+0.1f);
			mesh.vertexPositions.push_back(y * 0.1f);
			mesh.vertexPositions.push_back(0);

			mesh.vertexPositions.push_back(x * 0.1f);
			mesh.vertexPositions.push_back(y * 0.1f+0.1f);
			mesh.vertexPositions.push_back(0);

			mesh.vertexPositions.push_back(x * 0.1f+0.1f);
			mesh.vertexPositions.push_back(y * 0.1f+0.1f);
			mesh.vertexPositions.push_back(0);

			mesh.textureCoords.push_back(0 / 10.0f + 0.0f);
			mesh.textureCoords.push_back(1 / 10.0f + 0.9f);

			mesh.textureCoords.push_back(1 / 10.0f + 0.0f);
			mesh.textureCoords.push_back(0 / 10.0f + 0.9f);

			mesh.textureCoords.push_back(0 / 10.0f + 0.0f);
			mesh.textureCoords.push_back(1 / 10.0f + 0.9f);

			mesh.textureCoords.push_back(1 / 10.0f + 0.0f);
			mesh.textureCoords.push_back(1 / 10.0f + 0.9f);

			mesh.indices.push_back(0+x*4+y*4*size);
			mesh.indices.push_back(1+x*4+y*4*size);
			mesh.indices.push_back(3+x*4+y*4*size);

			mesh.indices.push_back(0+x*4+y*4*size);
			mesh.indices.push_back(2+x*4+y*4*size);
			mesh.indices.push_back(3+x*4+y*4*size);
		}
	}

	return mesh;
}

Mesh createSquareLessVertices(int size) {
	Mesh mesh;
	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			mesh.vertexPositions.push_back(x * 0.1f);
			mesh.vertexPositions.push_back(y * 0.1f);
			mesh.vertexPositions.push_back(0);

			mesh.textureCoords.push_back(x%2/10.0f+0.0f);
			mesh.textureCoords.push_back(y%2/10.0f+0.9f);
		}
	}

	for (int i = 0; i < (size - 1) * (size - 1); i++) {
		mesh.indices.push_back(i / (size - 1) + i);
		mesh.indices.push_back(i / (size - 1) + i + 1);
		mesh.indices.push_back(i / (size - 1) + i + size);
		mesh.indices.push_back(i / (size - 1) + i + 1);
		mesh.indices.push_back(i / (size - 1) + i + size);
		mesh.indices.push_back(i / (size - 1) + i + size + 1);
	}

	return mesh;
}

Model getSquareModel(int size) {
	Mesh squaremesh = createSquare(size);
	Model squaremodel(squaremesh);
	return squaremodel;
}

Model getSquareModelLess(int size) {
	Mesh squaremesh = createSquareLessVertices(size);
	Model squaremodel(squaremesh);
	return squaremodel;
}

void addSquareModelLess(int size, Renderer* renderer) {
	auto squareModel = new Model;
	*squareModel = getSquareModelLess(size);
	renderer->addModel(squareModel);
}

void addSquareModel(int size, Renderer* renderer) {
	auto squareModel = new Model;
	*squareModel = getSquareModel(size);
	renderer->addModel(squareModel);
}

#endif // !SQUAREMESH_H_INCLUDED