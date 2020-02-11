#ifndef HOUSE_H_INCLUDED
#define HOUSE_H_INCLUDED

#include "mesh.h"
#include "model.h"

Mesh createSquare(int size);
Model getSquareModel(int size);

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

			mesh.textureCoords.push_back(0);
			mesh.textureCoords.push_back(0);

			mesh.textureCoords.push_back(1);
			mesh.textureCoords.push_back(0);

			mesh.textureCoords.push_back(0);
			mesh.textureCoords.push_back(1);

			mesh.textureCoords.push_back(1);
			mesh.textureCoords.push_back(1);

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

Model getSquareModel(int size) {
	Mesh housemesh = createSquare(size);
	Model housemodel(housemesh);
	return housemodel;
}

#endif // !HOUSE_H_INCLUDED