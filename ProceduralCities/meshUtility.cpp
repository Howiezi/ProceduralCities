#include "meshUtility.h"
#include <math.h>
#include <iostream>

float gaussFunction(float peak, float x, float y, float deviation);

void changeHeightSquareLess(Mesh* mesh, float x, float y, float z) {
	int width = sqrt(mesh->vertexPositions.size()/3);
	std::cout << width << std::endl;
	mesh->vertexPositions[(y * width + x) * 3 + 2] = z;
	std::cout << (y * width + x) * 3 + 2 << std::endl;
}

void changeHeightWorldMesh(WorldMesh* mesh, float x, float y, float z) {
	if (x != mesh->width && y != mesh->height) {
		mesh->vertexPositions[(y * mesh->width + x) * 12 + 2] = z;
	}
	if (x != mesh->width && y != 0) {
		mesh->vertexPositions[((y-1) * mesh->width + x) * 12 + 8] = z;
	}
	if (x != 0 && y != mesh->height) {
		mesh->vertexPositions[(y * mesh->width + (x-1)) * 12 + 5] = z;
	}
	if (x != 0 && y != 0) {
		mesh->vertexPositions[((y-1) * mesh->width + (x-1)) * 12 + 11] = z;
	}
}

void changeTextureWorldMesh(WorldMesh* mesh, float x, float y) {
	mesh->textureCoords[(y * mesh->width + x) * 8] = 0 / 10.0f + 0.0f;
	mesh->textureCoords[(y * mesh->width + x) * 8 + 1] = 0 / 10.0f + 0.8f;
	
	mesh->textureCoords[(y * mesh->width + x) * 8 + 2] = 0 / 10.0f + 0.0f;
	mesh->textureCoords[(y * mesh->width + x) * 8 + 3] = 1 / 10.0f + 0.8f;

	mesh->textureCoords[(y * mesh->width + x) * 8 + 4] = 1 / 10.0f + 0.0f;
	mesh->textureCoords[(y * mesh->width + x) * 8 + 5] = 0 / 10.0f + 0.8f;
	
	mesh->textureCoords[(y * mesh->width + x) * 8 + 6] = 1 / 10.0f + 0.0f;
	mesh->textureCoords[(y * mesh->width + x) * 8 + 7] = 1 / 10.0f + 0.8f;
}

void createMountain(WorldMesh* mesh, float x, float y, float height, int radius) {
	for (int i = -radius; i <= radius; i++) {
		for (int j = -radius; j <= radius; j++) {
			int temp = sqrt(abs(i) * abs(i) + abs(j) * abs(j));
			if (temp >= radius) continue;
			changeHeightWorldMesh(mesh, x + i, y + j, gaussFunction(height,i,j,radius/2)*0.1f);
			changeTextureWorldMesh(mesh, x + i, y + j);
		}
	}
}

float gaussFunctionUtil(float peak, float x, float y, float deviation) {
	return peak * exp(-1 * (x*x + y*y) / (2 * deviation*deviation));
}