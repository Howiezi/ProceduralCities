#include "world.h"
#include "meshUtility.h"

WorldMesh createWorldFromFile(const std::string& fname) {
	ppm image(fname);

	WorldMesh heightmap;
	heightmap.height = image.height;
	heightmap.width = image.width;

	int kk = 0;

	for (int x = 0; x < image.width; x++) {
		for (int y = 0; y < image.height; y++) {
			heightmap.vertexPositions.push_back(x * 0.1f);
			heightmap.vertexPositions.push_back(y * 0.1f);
			//std::cout << image.r[kk]/25.5f << std::endl;

			heightmap.vertexPositions.push_back(1-image.r[kk]/255.0f);
			kk++;

			heightmap.textureCoords.push_back(x % 2 / 10.0f + 0.0f);
			heightmap.textureCoords.push_back(y % 2 / 10.0f + 0.9f);
		}
	}

	for (int i = 0; i < (image.width - 1) * (image.width - 1); i++) {
		heightmap.indices.push_back(i / (image.width - 1) + i);
		heightmap.indices.push_back(i / (image.width - 1) + i + 1);
		heightmap.indices.push_back(i / (image.width - 1) + i + image.width);
		heightmap.indices.push_back(i / (image.width - 1) + i + 1);
		heightmap.indices.push_back(i / (image.width - 1) + i + image.width);
		heightmap.indices.push_back(i / (image.width - 1) + i + image.width + 1);
	}


	createMountain(&heightmap, 50, 50);

	//changeHeightWorldMesh(&heightmap, 100, 100, 5000);
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