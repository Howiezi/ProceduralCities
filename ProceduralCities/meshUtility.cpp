#include "meshUtility.h"
#include <iostream>

void changeHeightSquareLess(Mesh* mesh, float x, float y, float z) {
	int width = sqrt(mesh->vertexPositions.size()/3);
	std::cout << width << std::endl;
	mesh->vertexPositions[(y * width + x) * 3 + 2] = z;
	std::cout << (y * width + x) * 3 + 2 << std::endl;
}

void changeHeightWorldMesh(WorldMesh* mesh, float x, float y, float z) {
	mesh->vertexPositions[(y * mesh->width + x) * 3 + 2] = z;
}

void changeTextureWorldMesh(WorldMesh* mesh, float x, float y) {
	mesh->textureCoords[(y * mesh->width + x) * 2] = int(x) % 2 / 10.0f + 0.0f;
	mesh->textureCoords[(y * mesh->width + x) * 2 + 1] = int(y) % 2 / 10.0f + 0.8f;
}

void createMountain(WorldMesh* mesh, float x, float y) {
	for (int i = -10; i <= 10; i++) {
		for (int j = -10; j <= 10; j++) {
			int temp = sqrt(abs(i) * abs(i) + abs(j) * abs(j));
			if (temp >= 10) continue;
			changeHeightWorldMesh(mesh, x + i, y + j, (10 - temp)*0.1f);
			changeTextureWorldMesh(mesh, x + i, y + j);
		}
	}
}