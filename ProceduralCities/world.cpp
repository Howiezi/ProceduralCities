#include "world.h"
#include "meshUtility.h"
#include "objects.h"
#include "texcoords.h"

WorldMesh createWorldFromFile(const std::string& fname) {
	ppm image(fname);

	WorldMesh heightmap;
	heightmap.height = image.height;
	heightmap.width = image.width;

	int kk = 0;

	for (int y = 0; y < image.height-1; y++) {
		for (int x = 0; x < image.width - 1; x++) {
			heightmap.vertexPositions.push_back(x * 0.1f);
			heightmap.vertexPositions.push_back(y * 0.1f);
			heightmap.vertexPositions.push_back(1 - image.r[kk] / 255.0f);

			heightmap.vertexPositions.push_back((x + 1) * 0.1f);
			heightmap.vertexPositions.push_back(y * 0.1f);
			heightmap.vertexPositions.push_back(1 - image.r[kk + 1] / 255.0f);

			heightmap.vertexPositions.push_back(x * 0.1f);
			heightmap.vertexPositions.push_back((y + 1) * 0.1f);
			heightmap.vertexPositions.push_back(1 - image.r[kk + image.width] / 255.0f);

			heightmap.vertexPositions.push_back((x+1) * 0.1f);
			heightmap.vertexPositions.push_back((y+1) * 0.1f);
			heightmap.vertexPositions.push_back(1 - image.r[kk+image.width+1] / 255.0f);
			
			kk++;

			heightmap.textureCoords.push_back(0 / 10.0f + 0.0f);
			heightmap.textureCoords.push_back(0 / 10.0f + 0.9f);

			heightmap.textureCoords.push_back(1 / 10.0f + 0.0f);
			heightmap.textureCoords.push_back(0 / 10.0f + 0.9f);

			heightmap.textureCoords.push_back(0 / 10.0f + 0.0f);
			heightmap.textureCoords.push_back(1 / 10.0f + 0.9f);

			heightmap.textureCoords.push_back(1 / 10.0f + 0.0f);
			heightmap.textureCoords.push_back(1 / 10.0f + 0.9f);

			heightmap.indices.push_back(0 + x * 4 + y * 4 * (image.width-1));
			heightmap.indices.push_back(1 + x * 4 + y * 4 * (image.width-1));
			heightmap.indices.push_back(2 + x * 4 + y * 4 * (image.width-1));
			heightmap.indices.push_back(1 + x * 4 + y * 4 * (image.width-1));
			heightmap.indices.push_back(2 + x * 4 + y * 4 * (image.width-1));
			heightmap.indices.push_back(3 + x * 4 + y * 4 * (image.width-1));
		}
		kk++;
	}

	createMountain(&heightmap, 50, 50, 20, 10);
	//changeHeightWorldMesh(&heightmap, 10, 100, 5000);
	return heightmap;
}

Model getWorldModelFromFile(const std::string& fname) {
	WorldMesh squaremesh = createWorldFromFile(fname);
	Model squaremodel(squaremesh);
	return squaremodel;
}

void addWorldModelFromFile(const std::string& fname, Renderer* renderer) {
	auto squareModel = new Model;
	*squareModel = getWorldModelFromFile(fname);
	renderer->addModel(squareModel);
}