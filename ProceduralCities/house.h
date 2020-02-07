#ifndef HOUSE_H_INCLUDED
#define HOUSE_H_INCLUDED

#include "mesh.h"
#include "model.h"

Mesh createHouse();
Model getHouseModel();

Mesh createHouse() {
	Mesh mesh;
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			mesh.vertexPositions.push_back(x);
			mesh.vertexPositions.push_back(y);
			mesh.vertexPositions.push_back(0);
		}
	}
	for (int i = 0; i < 9*9*6; i++) {
		mesh.indices.push_back(i / 9 + i);
		mesh.indices.push_back(i / 9 + i + 1);
		mesh.indices.push_back(i / 9 + i + 9);
		mesh.indices.push_back(i / 9 + i + 1);
		mesh.indices.push_back(i / 9 + i + 9);
		mesh.indices.push_back(i / 9 + i + 9 + 1);
	}
	return mesh;
}

Model getHouseModel() {
	Mesh housemesh = createHouse();
	Model housemodel(housemesh);
	return housemodel;
}

#endif // !HOUSE_H_INCLUDED