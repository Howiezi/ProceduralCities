#include "objects.h"
#include "texcoords.h"
#include <iostream>
#include <time.h>

Mesh getTreeMesh(float x, float y) {
	Mesh tree;
	int treeheight = 6;
	for (int i = 0; i < treeheight; i++) {
		tree.vertexPositions.push_back(x+0.0f+0.01f*i);
		tree.vertexPositions.push_back(y+0.0f+0.01f*i);
		tree.vertexPositions.push_back(i / float(treeheight-1));
		tree.textureCoords.push_back(0 / 10.0f + 0.1f);
		tree.textureCoords.push_back(i % 2 / 10.0f + 0.9f);

		tree.vertexPositions.push_back(x+0.1f-0.01f*i);
		tree.vertexPositions.push_back(y+0.0f+0.01f*i);
		tree.vertexPositions.push_back(i / float(treeheight-1));
		tree.textureCoords.push_back(1 / 10.0f + 0.1f);
		tree.textureCoords.push_back(i % 2 / 10.0f + 0.9f);

		tree.vertexPositions.push_back(x+0.0f+0.01f*i);
		tree.vertexPositions.push_back(y+0.1f-0.01f*i);
		tree.vertexPositions.push_back(i / float(treeheight-1));
		tree.textureCoords.push_back(1 / 10.0f + 0.1f);
		tree.textureCoords.push_back(i % 2 / 10.0f + 0.9f);

		tree.vertexPositions.push_back(x+0.1f-0.01f*i);
		tree.vertexPositions.push_back(y+0.1f-0.01f*i);
		tree.vertexPositions.push_back(i / float(treeheight-1));
		tree.textureCoords.push_back(0 / 10.0f + 0.1f);
		tree.textureCoords.push_back(i % 2 / 10.0f + 0.9f);
	}

	for (int i = 0; i < (treeheight-1); i++) {
		tree.indices.push_back(0 + i * 4);
		tree.indices.push_back(1 + i * 4);
		tree.indices.push_back(4 + i * 4);

		tree.indices.push_back(1 + i * 4);
		tree.indices.push_back(4 + i * 4);
		tree.indices.push_back(5 + i * 4);

		tree.indices.push_back(2 + i * 4);
		tree.indices.push_back(0 + i * 4);
		tree.indices.push_back(6 + i * 4);

		tree.indices.push_back(0 + i * 4);
		tree.indices.push_back(6 + i * 4);
		tree.indices.push_back(4 + i * 4);

		tree.indices.push_back(1 + i * 4);
		tree.indices.push_back(3 + i * 4);
		tree.indices.push_back(5 + i * 4);

		tree.indices.push_back(3 + i * 4);
		tree.indices.push_back(5 + i * 4);
		tree.indices.push_back(7 + i * 4);

		tree.indices.push_back(3 + i * 4);
		tree.indices.push_back(2 + i * 4);
		tree.indices.push_back(7 + i * 4);

		tree.indices.push_back(2 + i * 4);
		tree.indices.push_back(6 + i * 4);
		tree.indices.push_back(7 + i * 4);
	}
	return tree;
}

Mesh getBranchMesh(float x, float y) {
	Mesh branch;

	for (int i = 1; i < 5; i++) {
		branch.vertexPositions.push_back(x + -0.45f + 0.01f * i);
		branch.vertexPositions.push_back(y + 0.0f + 0.01f * i);
		branch.vertexPositions.push_back(i / 4.0f);

		branch.vertexPositions.push_back(x + 0.45f - 0.01f * i);
		branch.vertexPositions.push_back(y + 0.0f + 0.01f * i);
		branch.vertexPositions.push_back(i / 4.0f);

		branch.vertexPositions.push_back(x + -0.45f + 0.01f * i);
		branch.vertexPositions.push_back(y + -0.4f - 0.01f * i);
		branch.vertexPositions.push_back((i+1) / 4.0f);

		branch.vertexPositions.push_back(x + 0.45f - 0.01f * i);
		branch.vertexPositions.push_back(y + -0.4f - 0.01f * i);
		branch.vertexPositions.push_back((i+1) / 4.0f);

		branch.textureCoords.push_back(0 / 10.0f + 0.2f);
		branch.textureCoords.push_back(0 / 10.0f + 0.9f);

		branch.textureCoords.push_back(1 / 10.0f + 0.2f);
		branch.textureCoords.push_back(0 / 10.0f + 0.9f);

		branch.textureCoords.push_back(0 / 10.0f + 0.2f);
		branch.textureCoords.push_back(1 / 10.0f + 0.9f);

		branch.textureCoords.push_back(1 / 10.0f + 0.2f);
		branch.textureCoords.push_back(1 / 10.0f + 0.9f);
	}

	for (int i = 0; i < 4; i++) {
		branch.indices.push_back(0 + i * 4);
		branch.indices.push_back(1 + i * 4);
		branch.indices.push_back(2 + i * 4);

		branch.indices.push_back(1 + i * 4);
		branch.indices.push_back(2 + i * 4);
		branch.indices.push_back(3 + i * 4);
	}

	return branch;
}

Model getTreeModel(float x, float y) {
	Mesh treeMesh = getTreeMesh(x, y);
	Model treeModel(treeMesh);
	return treeModel;
}

Model getBranchModel(float x, float y) {
	Mesh branchMesh = getBranchMesh(x, y);
	Model branchModel(branchMesh);
	return branchModel;
}

void addTreeModel(float x, float y, Renderer* renderer) {
	auto treeModel = new Model;
	*treeModel = getTreeModel(x,y);
	renderer->addModel(treeModel);

	auto branchModel = new Model;
	*branchModel = getBranchModel(x, y);
	renderer->addModel(branchModel);
}

void readModelsTextfile(const std::string& fname, Renderer* renderer) {
	std::ifstream infile(fname);
	std::string line;
	while (std::getline(infile, line)) {

		std::istringstream iss(line);
		std::string type;
		std::string texture;

		if (!(iss >> type)) { break; }
		
		if (type == "sphere") {
			float x, y, z, r;
			if (!(iss >> x >> y >> z >> r)) { break; }
			if (!(iss >> texture)) { addSphereModel(x, y, z, r, renderer, "bark"); }
			else { addSphereModel(x, y, z, r, renderer, texture);}

		}
		else if (type == "tree") {
			float x, y;
			if (!(iss >> x >> y)) { break; }

			addTreeModel(x, y, renderer);
		}
		else if (type == "cylinder") {
			float x, y, z, r, h;
			if (!(iss >> x >> y >> z >> r >> h)) { break; }

			if (!(iss >> texture)) { addCylinderModel(x, y, z, r, h, renderer, "bark"); }
			else { addCylinderModel(x, y, z, r, h, renderer, texture); }
		}
		else if (type == "cube") {
			float x, y, z, l;
			if (!(iss >> x >> y >> z >> l)) { break; }

			if (!(iss >> texture)) { addCubeModel(x, y, z, l, renderer,"bark"); }
			else { addCubeModel(x, y, z, l, renderer,texture); }
		}
		else if (type == "torus") {
			float x, y, z, r1, r2;
			if (!(iss >> x >> y >> z >> r1 >> r2)) { break; }

			if (!(iss >> texture)) { addTorusModel(x, y, z, r1, r2, renderer,"bark"); }
			else { addTorusModel(x, y, z, r1, r2, renderer, texture); }
		}
		else if (type == "conical") {
			float x, y, z, rupp, rdown, h;
			if (!(iss >> x >> y >> z >> rupp >> rdown >> h)) { break; }

			if (!(iss >> texture)) { addConicalModel(x, y, z, rupp, rdown, h, renderer,"bark"); }
			else { addConicalModel(x, y, z, rupp, rdown, h, renderer, texture); }
		}
		else if (type == "cuboid") {
			float x, y, z, l, w, h;
			if (!(iss >> x >> y >> z >> l >> w >> h)) { break; }

			if (!(iss >> texture)) { addCuboidModel(x, y, z, l, w, h, renderer,"bark"); }
			else { addCuboidModel(x, y, z, l, w, h, renderer, texture); }
		}
		else if (type == "pyramid") {
			float x, y, z, r;
			if (!(iss >> x >> y >> z >> r)) { break; }

			if (!(iss >> texture)) { addPyramidModel(x, y, z, r, renderer, "bark"); }
			else { addPyramidModel(x, y, z, r, renderer, texture); }
		}
		else if (type == "road") {
			float x1, y1, x2, y2;
			if (!(iss >> x1 >> y1 >> x2 >> y2)) { break; }
			if (!(iss >> texture)) { createRoadBetter(x1, y1, x2, y2, renderer,"road"); }
			else { createRoadBetter(x1, y1, x2, y2, renderer,texture); }

		}
		else if (type == "mountain") {
			float x, y, height, radius;
			if (!(iss >> x >> y >> height >> radius)) { break; }
		
			addMountainModel(x, y, height, radius, renderer);
		}
		else {
			continue;
		}

	}
}

Mesh createSphereMesh(float r, int subdivision, const std::string& texture) {
	// Constants for angle calculations
	const float PI = 3.1415926f;
	const float H_ANGLE = PI / 180 * 72;
	const float V_ANGLE = atanf(1.0f / 2);

	Mesh sphere;

	float t1[2];

	getTexturecoords(t1, texture);

	for (int i = 0; i < 6; i++) {
		// The top vertex of the sphere
		sphere.vertexPositions.push_back(0);
		sphere.vertexPositions.push_back(0);
		sphere.vertexPositions.push_back(r);

		sphere.textureCoords.push_back((1.0f+2.0f*i) * 46 / 5120 + t1[0]);
		sphere.textureCoords.push_back(0.0f * 170 / 5120 + t1[1]);

		// Vertexes of upper layer
		sphere.vertexPositions.push_back(r * cosf(V_ANGLE) * cosf(H_ANGLE * i));
		sphere.vertexPositions.push_back(r * cosf(V_ANGLE) * sinf(H_ANGLE * i));
		sphere.vertexPositions.push_back(r * sinf(V_ANGLE));

		sphere.textureCoords.push_back(2.0f * i * 46 / 5120 + t1[0]);
		sphere.textureCoords.push_back(170.0f / 5120 + t1[1]);
		
		// Vertextes of bottom layer
		sphere.vertexPositions.push_back(r * cosf(V_ANGLE) * cosf(H_ANGLE * i + PI / 5));
		sphere.vertexPositions.push_back(r * cosf(V_ANGLE) * sinf(H_ANGLE * i + PI / 5));
		sphere.vertexPositions.push_back((-1) * r * sinf(V_ANGLE));

		sphere.textureCoords.push_back((2.0f * i + 1) * 46 / 5120 + t1[0]);
		sphere.textureCoords.push_back(2.0f * 170 / 5120 + t1[1]);

		// Bottom vertex of the sphere
		sphere.vertexPositions.push_back(0);
		sphere.vertexPositions.push_back(0);
		sphere.vertexPositions.push_back(-r);

		sphere.textureCoords.push_back((1.0f + 2.0f * i) * 46 / 5120 + t1[0]);
		sphere.textureCoords.push_back(3.0f * 170 / 5120 + t1[1]);

		if (i < 5) {
			// Top pentagon
			sphere.indices.push_back(i * 4 + 0);
			sphere.indices.push_back(i * 4 + 1);
			sphere.indices.push_back(i * 4 + 5);

			// Bottom pentagon
			sphere.indices.push_back(i * 4 + 2);
			sphere.indices.push_back(i * 4 + 3);
			sphere.indices.push_back(i * 4 + 6);

			// Ten side triangles
			sphere.indices.push_back(i * 4 + 1);
			sphere.indices.push_back(i * 4 + 2);
			sphere.indices.push_back(i * 4 + 5);

			sphere.indices.push_back(i * 4 + 2);
			sphere.indices.push_back(i * 4 + 5);
			sphere.indices.push_back(i * 4 + 6);
		}
	}

	subdivideSphere(subdivision, &sphere, r);

	return sphere;
}

Model getSphereModel(float x, float y, float z, float r, const std::string& texture) {
	Mesh spheremesh = createSphereMesh(r,4,texture);
	translateMesh(x, y, z, &spheremesh);
	Model spheremodel(spheremesh);
	return spheremodel;
}

void addSphereModel(float x,float y,float z, float r, Renderer* renderer, const std::string& texture) {
	auto sphereModel = new Model;
	*sphereModel = getSphereModel(x,y,z,r,texture);
	renderer->addModel(sphereModel);
}

void translateMesh(float x, float y, float z, Mesh* mesh) {
	for (int i = 0; i < mesh->vertexPositions.size(); i += 3) {
		mesh->vertexPositions[i] += x;
		mesh->vertexPositions[i+1] += y;
		mesh->vertexPositions[i+2] += z;
	}
}

void subdivideSphere(int subdivision, Mesh* sphere, float r) {
	std::vector<GLfloat> tmpVertices;
	std::vector<GLuint> tmpIndices;
	std::vector<GLfloat> tmpTextures;
	const float* v1, * v2, * v3;          // ptr to original vertices of a triangle
	float newV1[3], newV2[3], newV3[3]; // new vertex positions
	unsigned int index;

	const float* t1, * t2, * t3;          // ptr to original textures of a triangle
	float newT1[3], newT2[3], newT3[3]; // new texture positions
	// iterate all subdivision levels
	for (int i = 1; i <= subdivision; ++i)
	{
		// copy prev vertex/index arrays and clear
		tmpVertices = sphere->vertexPositions;
		tmpIndices = sphere->indices;
		tmpTextures = sphere->textureCoords;
		sphere->vertexPositions.clear();
		sphere->textureCoords.clear();
		sphere->indices.clear();
		index = 0;

		// perform subdivision for each triangle
		for (int j = 0; j < tmpIndices.size(); j += 3)
		{
			// get 3 vertices of a triangle
			v1 = &tmpVertices[tmpIndices[j] * 3];
			v2 = &tmpVertices[tmpIndices[j + 1] * 3];
			v3 = &tmpVertices[tmpIndices[j + 2] * 3];

			// get 3 textures of a triangle
			t1 = &tmpTextures[tmpIndices[j] * 2];
			t2 = &tmpTextures[tmpIndices[j + 1] * 2];
			t3 = &tmpTextures[tmpIndices[j + 2] * 2];

			// compute 3 new textures
			newT1[0] = (t1[0] + t2[0]) / 2;
			newT2[0] = (t2[0] + t3[0]) / 2;
			newT3[0] = (t1[0] + t3[0]) / 2;

			newT1[1] = (t1[1] + t2[1]) / 2;
			newT2[1] = (t2[1] + t3[1]) / 2;
			newT3[1] = (t1[1] + t3[1]) / 2;

			// compute 3 new vertices by spliting half on each edge
			//         v1       
			//        / \       
			// newV1 *---* newV3
			//      / \ / \     
			//    v2---*---v3   
			//       newV2      
			computeHalfVertex(v1, v2, newV1, r);
			computeHalfVertex(v2, v3, newV2, r);
			computeHalfVertex(v1, v3, newV3, r);

			// add 4 new triangles to vertex array
			addVertices(v1, newV1, newV3, sphere);
			addVertices(newV1, v2, newV2, sphere);
			addVertices(newV1, newV2, newV3, sphere);
			addVertices(newV3, newV2, v3, sphere);

			// add 4 new textures
			addTextures(t1, newT1, newT3, sphere);
			addTextures(newT1, t2, newT2, sphere);
			addTextures(newT1, newT2, newT3, sphere);
			addTextures(newT3, newT2, t3, sphere);

			// add indices of 4 new triangles
			addIndices(index, index + 1, index + 2, sphere);
			addIndices(index + 3, index + 4, index + 5, sphere);
			addIndices(index + 6, index + 7, index + 8, sphere);
			addIndices(index + 9, index + 10, index + 11, sphere);
			index += 12;    // next index
		}
	}
	//std::cout << "Vertex count: " << sphere->vertexPositions.size()/3 << std::endl;
	//std::cout << "Index count: " << sphere->indices.size() << std::endl;
}

void addVertices(const float v1[3], const float v2[3], const float v3[3], Mesh* mesh) {
	mesh->vertexPositions.insert(mesh->vertexPositions.end(), v1, v1 + 3);
	mesh->vertexPositions.insert(mesh->vertexPositions.end(), v2, v2 + 3);
	mesh->vertexPositions.insert(mesh->vertexPositions.end(), v3, v3 + 3);
}

void addIndices(const unsigned int i1, const unsigned int i2, const unsigned int i3, Mesh* mesh) {
	mesh->indices.push_back(i1);
	mesh->indices.push_back(i2);
	mesh->indices.push_back(i3);
}

void addTextures(const float t1[2], const float t2[2], const float t3[2], Mesh* mesh) {
	mesh->textureCoords.insert(mesh->textureCoords.end(), t1, t1 + 2);
	mesh->textureCoords.insert(mesh->textureCoords.end(), t2, t2 + 2);
	mesh->textureCoords.insert(mesh->textureCoords.end(), t3, t3 + 2);
}

void computeHalfVertex(const float v1[3], const float v2[3], float newV[3], float radius)
{
	newV[0] = v1[0] + v2[0];    // x
	newV[1] = v1[1] + v2[1];    // y
	newV[2] = v1[2] + v2[2];    // z
	float scale = radius / sqrtf(newV[0] * newV[0] + newV[1] * newV[1] + newV[2] * newV[2]);
	newV[0] *= scale;
	newV[1] *= scale;
	newV[2] *= scale;
}

Mesh createCylinderMesh(float r, float h, const std::string& texture) {
	Mesh cylinder;

	// Constants for angle calculations
	const int SEGMENTS = 24;
	const float PI = 3.1415926f;
	const float H_ANGLE = PI / 180 * 360 / SEGMENTS;
	const float V_ANGLE = atanf(1.0f / 2);

	// The top vertex of the sphere
	float top[3] = { 0,0,h / 2 };
	float bottom[3] = { 0,0,-h / 2 };
	float nextT[3] = { r * cosf(H_ANGLE * 1),r * sinf(H_ANGLE * 1),h / 2 };
	float prevT[3] = { r * cosf(H_ANGLE * 0),r * sinf(H_ANGLE * 0),h / 2 };
	float nextB[3] = { r * cosf(H_ANGLE * 1),r * sinf(H_ANGLE * 1),-h / 2 };
	float prevB[3] = { r * cosf(H_ANGLE * 0),r * sinf(H_ANGLE * 0),-h / 2 };

	int index = 0;

	for (int i = 2; i < SEGMENTS+2; i++) {
		addVertices(top, nextT, prevT, &cylinder);
		addVertices(nextB, nextT, prevT, &cylinder);
		addVertices(nextB, prevT, prevB, &cylinder);
		addVertices(bottom, nextB, prevB, &cylinder);

		float t1[2], t2[2], t3[2], t4[2], t5[2], t6[2], t7[2];

		getTexturecoords(t1, texture);
		getTexturecoords(t2, texture);
		getTexturecoords(t3, texture);

		getTexturecoords(t4, texture);
		getTexturecoords(t5, texture);
		getTexturecoords(t6, texture);
		getTexturecoords(t7, texture);

		addRelativetoTexture(t1, 0.5f, 0.5f);
		addRelativetoTexture(t2, 0.5f + cosf(H_ANGLE * i)/2, 0.5f + sinf(H_ANGLE * i)/2);
		addRelativetoTexture(t3, 0.5f + cosf(H_ANGLE * (i+1))/2, 0.5f + sinf(H_ANGLE * (i+1))/2);

		addRelativetoTexture(t4, 1.0f / SEGMENTS * (i-2), 1.0f);
		addRelativetoTexture(t5, 1.0f / SEGMENTS * (i-1), 1.0f);
		addRelativetoTexture(t6, 1.0f / SEGMENTS * (i-2), 0.0f);
		addRelativetoTexture(t7, 1.0f / SEGMENTS * (i-1), 0.0f);

		// add 4 new textures
		addTextures(t1, t3, t2, &cylinder);
		addTextures(t7, t5, t4, &cylinder);
		addTextures(t7, t4, t6, &cylinder);
		addTextures(t1, t3, t2, &cylinder);

		addIndices(index, index + 1, index + 2, &cylinder);
		addIndices(index + 3, index + 4, index + 5, &cylinder);
		addIndices(index + 6, index + 7, index + 8, &cylinder);
		addIndices(index + 9, index + 10, index + 11, &cylinder);

		index += 12;

		prevT[0] = nextT[0];
		prevB[0] = nextB[0];
		prevT[1] = nextT[1];
		prevB[1] = nextB[1];
		nextT[0] = r * cosf(H_ANGLE * i);
		nextT[1] = r * sinf(H_ANGLE * i);
		nextB[0] = r * cosf(H_ANGLE * i);
		nextB[1] = r * sinf(H_ANGLE * i);
	}

	return cylinder;
}

Model getCylinderModel(float x, float y, float z, float r, float h, const std::string& texture) {
	Mesh cylinderMesh = createCylinderMesh(r * 0.1f, h * 0.1f,texture);
	translateMesh(x * 0.1f, y * 0.1f, z * 0.1f, &cylinderMesh);
	Model cylinderModel(cylinderMesh);
	return cylinderModel;
}

void addCylinderModel(float x, float y, float z, float r, float h, Renderer* renderer, const std::string& texture) {
	auto cylinderModel = new Model;
	*cylinderModel = getCylinderModel(x, y, z, r, h,texture);
	renderer->addModel(cylinderModel);
}

Mesh createCubeMesh(float l, const std::string& texture) {
	Mesh cube;

	float top1[3] = { l / 2,l / 2,l / 2 };
	float top2[3] = { l / 2,-l / 2,l / 2 };
	float top3[3] = { -l / 2,l / 2,l / 2 };
	float top4[3] = { -l / 2,-l / 2,l / 2 };

	float bottom1[3] = { l / 2,l / 2,-l / 2 };
	float bottom2[3] = { l / 2,-l / 2,-l / 2 };
	float bottom3[3] = { -l / 2,l / 2,-l / 2 };
	float bottom4[3] = { -l / 2,-l / 2,-l / 2 };

	addVertices(top1, top2, top3, &cube);
	addVertices(top2, top3, top4, &cube);

	addVertices(top1, top2, bottom1, &cube);
	addVertices(top2, bottom1, bottom2, &cube);

	addVertices(top2, top4, bottom2, &cube);
	addVertices(top4, bottom2, bottom4, &cube);

	addVertices(top3, top1, bottom3, &cube);
	addVertices(top1, bottom3, bottom1, &cube);

	addVertices(top4, top3, bottom4, &cube);
	addVertices(top3, bottom4, bottom3, &cube);

	addVertices(bottom1, bottom2, bottom3, &cube);
	addVertices(bottom2, bottom3, bottom4, &cube);

	float t1[2], t2[2], t3[2], t4[2];

	getTexturecoords(t1, texture);
	getTexturecoords(t2, texture);
	getTexturecoords(t3, texture);
	getTexturecoords(t4, texture);

	addRelativetoTexture(t2, 1.0f, 0.0f);
	addRelativetoTexture(t3, 0.0f, 1.0f);
	addRelativetoTexture(t4, 1.0f, 1.0f);

	for (int i = 0; i < 36; i += 6) {
		addIndices(i, i + 1, i + 2, &cube);
		addIndices(i + 3, i + 4, i + 5, &cube);
		addTextures(t1, t2, t3, &cube);
		addTextures(t2, t3, t4, &cube);
	}

	return cube;
}

Model getCubeModel(float x, float y, float z, float l, const std::string& texture) {
	Mesh cubeMesh = createCubeMesh(l * 0.1f,texture);
	translateMesh(x * 0.1f, y * 0.1f, z * 0.1f, &cubeMesh);
	Model cubeModel(cubeMesh);
	return cubeModel;
}

void addCubeModel(float x, float y, float z, float l, Renderer* renderer, const std::string& texture) {
	auto cubeModel = new Model;
	*cubeModel = getCubeModel(x, y, z, l,texture);
	renderer->addModel(cubeModel);
}

Mesh createTorusMesh(float r1, float r2, const std::string& texture) {
	Mesh torus;

	// Constants for angle calculations
	const int SEGMENTSR1 = 48;
	const int SEGMENTSR2 = 24;
	const float PI = 3.1415926f;
	const float R1_ANGLE = PI / 180 * 360 / SEGMENTSR1;
	const float R2_ANGLE = PI / 180 * 360 / SEGMENTSR2;

	float prevI[3] = { cosf(R1_ANGLE * 0) * (r1 + r2 * cosf(R2_ANGLE * 0)),sinf(R1_ANGLE * 0) * (r1 + r2 * cosf(R2_ANGLE * 0)),r2 * sinf(R2_ANGLE * 0) };
	float nextI[3] = { cosf(R1_ANGLE * 1) * (r1 + r2 * cosf(R2_ANGLE * 0)),sinf(R1_ANGLE * 1) * (r1 + r2 * cosf(R2_ANGLE * 0)),r2 * sinf(R2_ANGLE * 0) };

	float prevO[3] = { cosf(R1_ANGLE * 0) * (r1 + r2 * cosf(R2_ANGLE * 1)),sinf(R1_ANGLE * 0) * (r1 + r2 * cosf(R2_ANGLE * 1)),r2 * sinf(R2_ANGLE * 1) };
	float nextO[3] = { cosf(R1_ANGLE * 1) * (r1 + r2 * cosf(R2_ANGLE * 1)),sinf(R1_ANGLE * 1) * (r1 + r2 * cosf(R2_ANGLE * 1)),r2 * sinf(R2_ANGLE * 1) };
	
	int index = 0;

	for (int i = 2; i < SEGMENTSR1 + 2; i++) {
		for (int j = 2; j < SEGMENTSR2 + 2; j++) {
			addVertices(prevI, nextI, prevO, &torus);
			addVertices(nextI, prevO, nextO, &torus);

			float t1[2], t2[2], t3[2], t4[2];

			getTexturecoords(t1, texture);
			getTexturecoords(t2, texture);
			getTexturecoords(t3, texture);
			getTexturecoords(t4, texture);

			addRelativetoTexture(t1, 0.0f, 0.0f);
			addRelativetoTexture(t2, 1.0f, 0.0f);
			addRelativetoTexture(t3, 1.0f, 1.0f);
			addRelativetoTexture(t4, 0.0f, 1.0f);

			addTextures(t4, t3, t1, &torus);
			addTextures(t3, t1, t2, &torus);

			addIndices(index, index + 1, index + 2, &torus);
			addIndices(index + 3, index + 4, index + 5, &torus);

			index += 6;

			prevI[0] = prevO[0];
			prevI[1] = prevO[1];
			prevI[2] = prevO[2];
			nextI[0] = nextO[0];
			nextI[1] = nextO[1];
			nextI[2] = nextO[2];

			nextO[0] = cosf(R1_ANGLE * (i - 1)) * (r1 + r2 * cosf(R2_ANGLE * j));
			nextO[1] = sinf(R1_ANGLE * (i - 1)) * (r1 + r2 * cosf(R2_ANGLE * j));
			nextO[2] = r2 * sinf(R2_ANGLE * j);
			prevO[0] = cosf(R1_ANGLE * (i - 2)) * (r1 + r2 * cosf(R2_ANGLE * j));
			prevO[1] = sinf(R1_ANGLE * (i - 2)) * (r1 + r2 * cosf(R2_ANGLE * j));
			prevO[2] = r2 * sinf(R2_ANGLE * j);
		}

		prevI[0] = nextI[0];
		prevI[1] = nextI[1];
		prevO[0] = nextO[0];
		prevO[1] = nextO[1];

		nextO[0] = cosf(R1_ANGLE * i) * (r1 + r2 * cosf(R2_ANGLE * 1));
		nextO[1] = sinf(R1_ANGLE * i) * (r1 + r2 * cosf(R2_ANGLE * 1));
		nextI[0] = cosf(R1_ANGLE * i) * (r1 + r2 * cosf(R2_ANGLE * 0));
		nextI[1] = sinf(R1_ANGLE * i) * (r1 + r2 * cosf(R2_ANGLE * 0));
	}

	return torus;
}

Model getTorusModel(float x, float y, float z, float r1, float r2, const std::string& texture) {
	Mesh torusMesh = createTorusMesh(r1 * 0.1f, r2 * 0.1f,texture);
	translateMesh(x * 0.1f, y * 0.1f, z * 0.1f, &torusMesh);
	Model torusModel(torusMesh);
	return torusModel;
}

void addTorusModel(float x, float y, float z, float r1, float r2, Renderer* renderer, const std::string& texture) {
	auto torusModel = new Model;
	*torusModel = getTorusModel(x, y, z, r1, r2,texture);
	renderer->addModel(torusModel);
}

Mesh createConicalMesh(float rupp, float rdown, float h, const std::string& texture) {
	Mesh conical;

	// Constants for angle calculations
	const int SEGMENTS = 24;
	const float PI = 3.1415926f;
	const float H_ANGLE = PI / 180 * 360 / SEGMENTS;
	const float V_ANGLE = atanf(1.0f / 2);

	// The top vertex of the sphere
	float top[3] = { 0,0,h / 2 };
	float bottom[3] = { 0,0,-h / 2 };
	float nextT[3] = { rupp * cosf(H_ANGLE * 1),rupp * sinf(H_ANGLE * 1),h / 2 };
	float prevT[3] = { rupp * cosf(H_ANGLE * 0),rupp * sinf(H_ANGLE * 0),h / 2 };
	float nextB[3] = { rdown * cosf(H_ANGLE * 1),rdown * sinf(H_ANGLE * 1),-h / 2 };
	float prevB[3] = { rdown * cosf(H_ANGLE * 0),rdown * sinf(H_ANGLE * 0),-h / 2 };

	int index = 0;

	for (int i = 2; i < SEGMENTS + 2; i++) {
		addVertices(top, nextT, prevT, &conical);
		addVertices(nextB, nextT, prevT, &conical);
		addVertices(nextB, prevT, prevB, &conical);
		addVertices(bottom, nextB, prevB, &conical);

		float t1[2], t2[2], t3[2], t4[2], t5[2], t6[2], t7[2];

		getTexturecoords(t1, texture);
		getTexturecoords(t2, texture);
		getTexturecoords(t3, texture);

		getTexturecoords(t4, texture);
		getTexturecoords(t5, texture);
		getTexturecoords(t6, texture);
		getTexturecoords(t7, texture);

		addRelativetoTexture(t1, 0.5f, 0.5f);
		addRelativetoTexture(t2, 0.5f + cosf(H_ANGLE * i) / 2, 0.5f + sinf(H_ANGLE * i) / 2);
		addRelativetoTexture(t3, 0.5f + cosf(H_ANGLE * (i + 1)) / 2, 0.5f + sinf(H_ANGLE * (i + 1)) / 2);

		addRelativetoTexture(t4, 1.0f / SEGMENTS * (i - 2), 1.0f);
		addRelativetoTexture(t5, 1.0f / SEGMENTS * (i - 1), 1.0f);
		addRelativetoTexture(t6, 1.0f / SEGMENTS * (i - 2), 0.0f);
		addRelativetoTexture(t7, 1.0f / SEGMENTS * (i - 1), 0.0f);

		// add 4 new textures
		addTextures(t1, t3, t2, &conical);
		addTextures(t7, t5, t4, &conical);
		addTextures(t7, t4, t6, &conical);
		addTextures(t1, t3, t2, &conical);

		addIndices(index, index + 1, index + 2, &conical);
		addIndices(index + 3, index + 4, index + 5, &conical);
		addIndices(index + 6, index + 7, index + 8, &conical);
		addIndices(index + 9, index + 10, index + 11, &conical);

		index += 12;

		prevT[0] = nextT[0];
		prevB[0] = nextB[0];
		prevT[1] = nextT[1];
		prevB[1] = nextB[1];
		nextT[0] = rupp * cosf(H_ANGLE * i);
		nextT[1] = rupp * sinf(H_ANGLE * i);
		nextB[0] = rdown * cosf(H_ANGLE * i);
		nextB[1] = rdown * sinf(H_ANGLE * i);
	}

	return conical;
}

Model getConicalModel(float x, float y, float z, float rupp, float rdown, float h, const std::string& texture) {
	Mesh conicalMesh = createConicalMesh(rupp * 0.1f, rdown * 0.1f, h * 0.1f,texture);
	translateMesh(x * 0.1f, y * 0.1f, z * 0.1f, &conicalMesh);
	Model conicalModel(conicalMesh);
	return conicalModel;
}

void addConicalModel(float x, float y, float z, float rupp, float rdown, float h, Renderer* renderer,const std::string& texture) {
	auto conicalModel = new Model;
	*conicalModel = getConicalModel(x, y, z, rupp, rdown, h,texture);
	renderer->addModel(conicalModel);
}

Mesh createCuboidMesh(float l, float w,float h, const std::string& texture) {
	Mesh cuboid;

	float top1[3] = { l / 2,w / 2,h/ 2 };
	float top2[3] = { l / 2,-w / 2,h / 2 };
	float top3[3] = { -l / 2,w / 2,h / 2 };
	float top4[3] = { -l / 2,-w / 2,h/ 2 };

	float bottom1[3] = { l / 2,w / 2,-h / 2 };
	float bottom2[3] = { l / 2,-w / 2,-h / 2 };
	float bottom3[3] = { -l / 2,w / 2,-h / 2 };
	float bottom4[3] = { -l / 2,-w / 2,-h / 2 };

	addVertices(top1, top2, top3, &cuboid);
	addVertices(top2, top3, top4, &cuboid);

	addVertices(top1, top2, bottom1, &cuboid);
	addVertices(top2, bottom1, bottom2, &cuboid);

	addVertices(top2, top4, bottom2, &cuboid);
	addVertices(top4, bottom2, bottom4, &cuboid);

	addVertices(top3, top1, bottom3, &cuboid);
	addVertices(top1, bottom3, bottom1, &cuboid);

	addVertices(top4, top3, bottom4, &cuboid);
	addVertices(top3, bottom4, bottom3, &cuboid);

	addVertices(bottom1, bottom2, bottom3, &cuboid);
	addVertices(bottom2, bottom3, bottom4, &cuboid);

	float t1[2], t2[2], t3[2], t4[2];

	getTexturecoords(t1, texture);
	getTexturecoords(t2, texture);
	getTexturecoords(t3, texture);
	getTexturecoords(t4, texture);

	addRelativetoTexture(t2, 1.0f, 0.0f);
	addRelativetoTexture(t3, 0.0f, 1.0f);
	addRelativetoTexture(t4, 1.0f, 1.0f);

	for (int i = 0; i < 36; i += 6) {
		addIndices(i, i + 1, i + 2, &cuboid);
		addIndices(i + 3, i + 4, i + 5, &cuboid);
		addTextures(t1, t2, t3, &cuboid);
		addTextures(t2, t3, t4, &cuboid);
	}

	return cuboid;
}

Model getCuboidModel(float x, float y, float z, float l, float w, float h, const std::string& texture) {
	Mesh cuboidMesh = createCuboidMesh(l*0.1f, w * 0.1f, h * 0.1f,texture);
	translateMesh(x * 0.1f, y * 0.1f, z * 0.1f, &cuboidMesh);
	Model cuboidModel(cuboidMesh);
	return cuboidModel;
}

void addCuboidModel(float x, float y, float z, float l, float w, float h, Renderer* renderer, const std::string& texture) {
	auto cuboidModel = new Model;
	*cuboidModel = getCuboidModel(x, y, z, l, w, h,texture);
	renderer->addModel(cuboidModel);
}

Mesh createPyramidMesh(float r, const std::string& texture) {
	Mesh pyramid;

	float top[3] = { 0,0,r };

	float bottom1[3] = { r * sqrt(8) / 3,0,-r / 3 };
	float bottom2[3] = { -r * sqrt(8) / 6,r * sqrt(6) / 3,-r / 3 };
	float bottom3[3] = { -r * sqrt(8) / 6,-r * sqrt(6) / 3,-r / 3 };

	addVertices(top, bottom1, bottom2, &pyramid);
	addVertices(top, bottom2, bottom3, &pyramid);
	addVertices(top, bottom3, bottom1, &pyramid);
	addVertices(bottom1, bottom2, bottom3, &pyramid);

	float t1[2], t2[2], t3[2];

	getTexturecoords(t1, texture);
	getTexturecoords(t2, texture);
	getTexturecoords(t3, texture);

	addRelativetoTexture(t1, 0.5f, 1.0f);
	addRelativetoTexture(t2, 0.0f, 0.0f);
	addRelativetoTexture(t3, 1.0f, 0.0f);

	for (int i = 0; i < 12; i += 3) {
		addIndices(i, i + 1, i + 2, &pyramid);
		addTextures(t1, t2, t3, &pyramid);
	}

	return pyramid;
}

Model getPyramidModel(float x, float y, float z, float r, const std::string& texture) {
	Mesh pyramidMesh = createPyramidMesh(r * 0.1f,texture);
	translateMesh(x * 0.1f, y * 0.1f, z * 0.1f, &pyramidMesh);
	Model pyramidModel(pyramidMesh);
	return pyramidModel;
}

void addPyramidModel(float x, float y, float z, float r, Renderer* renderer, const std::string& texture) {
	auto pyramidModel = new Model;
	*pyramidModel = getPyramidModel(x, y, z, r, texture);
	renderer->addModel(pyramidModel);
}

void createRoad(int x1, int y1, int x2, int y2, Renderer* renderer, const std::string& texture) {
	const int ROADSUBDIVISION = 10;
	int xcoords[ROADSUBDIVISION + 2];
	int ycoords[ROADSUBDIVISION + 2];

	xcoords[0] = x1;
	xcoords[ROADSUBDIVISION + 1] = x2;
	ycoords[0] = y1;
	ycoords[ROADSUBDIVISION + 1] = y2;

	int xlength = abs(x1 - x2);
	int ylength = abs(y1 - y2);

	//std::cout << xlength << " " << ylength << std::endl;
	int disp = 0;

	for (int i = 1; i < ROADSUBDIVISION + 1; i++) {
		disp = rand() % 10;

		xcoords[i] = x1 + xlength * i / (ROADSUBDIVISION + 1) + disp / (i % 3 + 1);
		ycoords[i] = y1 + ylength * i / (ROADSUBDIVISION + 1) + disp / (i % 3 + 1);
		//fstd::cout << xcoords[i] << " " << ycoords[i] << std::endl;
	}

	addRoadModel(xcoords, ycoords, ROADSUBDIVISION + 2, renderer, texture);
}

void createRoadBetter(int x1, int y1, int x2, int y2, Renderer* renderer, const std::string& texture) {
	const int ROADSUBDIVISION = 3;
	const int arraysize = (1 << ROADSUBDIVISION) + 1;
	int xcoords[arraysize];
	int ycoords[arraysize];
	srand(time(NULL));

	xcoords[0] = x1;
	xcoords[arraysize-1] = x2;
	ycoords[0] = y1;
	ycoords[arraysize-1] = y2;

	int xlength = abs(x1 - x2);
	int ylength = abs(y1 - y2);

	int xsectionlength = xlength / (arraysize - 1);
	int ysectionlength = ylength / (arraysize - 1);

	//std::cout << xlength << " " << ylength << std::endl;
	int dispx = 0;
	int dispy = 0;

	int sections = 0;
	int newpoints = 0;

	int index = 0;

	for (int i = 0; i < ROADSUBDIVISION; i++) {
		sections = 1 << (i+1);
		newpoints = 1 << i;

		index = 1 << (ROADSUBDIVISION - 1 - i);
		for (int j = 0; j < newpoints; j++) {
			if (xsectionlength!=0) dispx = rand() % (xsectionlength);
			if (ysectionlength!=0) dispy = rand() % (ysectionlength);

			xcoords[index] = x1 + xsectionlength*index + dispx;
			ycoords[index] = y1 + ysectionlength*index + dispy;
			//std::cout << xcoords[index] << " " << ycoords[index] << " " << index << std::endl;
			index = index + (arraysize - 1) / newpoints;
		}
	}

	addRoadModel(xcoords, ycoords, arraysize, renderer, texture);
}

Mesh createRoadMesh(int* xcoords, int* ycoords, int size, const std::string& texture) {
	const float ROADWIDTH = 1.5f;
	const float PI = 3.1415926f;

	Mesh roadMesh;

	float vertex1[3], vertex2[3], vertex3[3], vertex4[3];
	float tex1[2], tex2[2], tex3[2], tex4[2];

	float xlen = xcoords[1] - xcoords[0];
	float ylen = ycoords[1] - ycoords[0];

	float angle = atanf(ylen / xlen) + PI / 2.0f;

	vertex1[0] = (xcoords[0] + ROADWIDTH * cosf(angle)) * 0.1f;
	vertex1[1] = (ycoords[0] + ROADWIDTH * sinf(angle)) * 0.1f;
	vertex2[0] = (xcoords[0] - ROADWIDTH * cosf(angle)) * 0.1f;
	vertex2[1] = (ycoords[0] - ROADWIDTH * sinf(angle)) * 0.1f;

	vertex1[2] = 0.001f;
	vertex2[2] = 0.001f;
	vertex3[2] = 0.001f;
	vertex4[2] = 0.001f;

	for (int i = 1; i < size; i++) {
		xlen = xcoords[i+1] - xcoords[i];
		ylen = ycoords[i+1] - ycoords[i];

		float newangle = atanf(ylen / xlen) + PI / 2.0f;
		angle = (angle + newangle) / 2.0f;
		//std::cout << xlen << " " << ylen << std::endl;
		//std::cout << angle << std::endl;

		vertex3[0] = (xcoords[i] + ROADWIDTH * cosf(angle)) * 0.1f;
		vertex3[1] = (ycoords[i] + ROADWIDTH * sinf(angle)) * 0.1f;
		vertex4[0] = (xcoords[i] - ROADWIDTH * cosf(angle)) * 0.1f;
		vertex4[1] = (ycoords[i] - ROADWIDTH * sinf(angle)) * 0.1f;

		getTexturecoords(tex1, texture);
		getTexturecoords(tex2, texture);
		getTexturecoords(tex3, texture);
		getTexturecoords(tex4, texture);

		addRelativetoTexture(tex1, 0.0f, 0.0f);
		addRelativetoTexture(tex2, 1.0f, 0.0f);
		addRelativetoTexture(tex3, 0.0f, 1.0f);
		addRelativetoTexture(tex4, 1.0f, 1.0f);

		addVertices(vertex1, vertex2, vertex3, &roadMesh);
		addVertices(vertex2, vertex3, vertex4, &roadMesh);

		addTextures(tex1, tex2, tex3, &roadMesh);
		addTextures(tex2, tex3, tex4, &roadMesh);

		addIndices((i - 1) * 6 + 0, (i - 1) * 6 + 1, (i - 1) * 6 + 2, &roadMesh);
		addIndices((i - 1) * 6 + 3, (i - 1) * 6 + 4, (i - 1) * 6 + 5, &roadMesh);

		vertex1[0] = vertex3[0];
		vertex1[1] = vertex3[1];
		vertex1[2] = vertex3[2];
		vertex2[0] = vertex4[0];
		vertex2[1] = vertex4[1];
		vertex2[2] = vertex4[2];
	}

	return roadMesh;
}

Model getRoadModel(int* xcoords, int* ycoords, int size, const std::string& texture) {
	Mesh roadMesh = createRoadMesh(xcoords, ycoords, size,texture);
	Model roadModel(roadMesh);
	return roadModel;
}

void addRoadModel(int* xcoords, int* ycoords, int size, Renderer* renderer, const std::string& texture) {
	auto roadModel = new Model;
	*roadModel = getRoadModel(xcoords, ycoords, size,texture);
	renderer->addModel(roadModel);
}

Mesh createMountainMesh(float h, float r) {
	Mesh mountainMesh;
	std::string texture;

	float t1[2], t2[2], t3[2], t4[2];
	int index = 0;
	float currentHeight = 0;

	for (int i = -r; i <= r; i++) {
		for (int j = -r; j <= r; j++) {
			int temp = sqrt(abs(i) * abs(i) + abs(j) * abs(j));
			if (temp >= r) continue;
			mountainMesh.vertexPositions.push_back((i + 0.5f)*0.1f);
			mountainMesh.vertexPositions.push_back((j + 0.5f) * 0.1f);
			mountainMesh.vertexPositions.push_back(gaussFunction(h, i + 0.5f, j + 0.5f, r / 2) * 0.1f);

			mountainMesh.vertexPositions.push_back((i + 0.5f) * 0.1f);
			mountainMesh.vertexPositions.push_back((j - 0.5f) * 0.1f);
			mountainMesh.vertexPositions.push_back(gaussFunction(h, i + 0.5f, j - 0.5f, r / 2) * 0.1f);

			mountainMesh.vertexPositions.push_back((i - 0.5f)*0.1f);
			mountainMesh.vertexPositions.push_back((j + 0.5f)*0.1f);
			mountainMesh.vertexPositions.push_back(gaussFunction(h, i - 0.5f, j + 0.5f, r / 2) * 0.1f);

			mountainMesh.vertexPositions.push_back((i + 0.5f)*0.1f);
			mountainMesh.vertexPositions.push_back((j - 0.5f)*0.1f);
			mountainMesh.vertexPositions.push_back(gaussFunction(h, i + 0.5f, j - 0.5f, r / 2) * 0.1f);

			mountainMesh.vertexPositions.push_back((i - 0.5f)*0.1f);
			mountainMesh.vertexPositions.push_back((j + 0.5f)*0.1f);
			mountainMesh.vertexPositions.push_back(gaussFunction(h, i - 0.5f, j + 0.5f, r / 2) * 0.1f);

			mountainMesh.vertexPositions.push_back((i - 0.5f)*0.1f);
			mountainMesh.vertexPositions.push_back((j - 0.5f)*0.1f);
			mountainMesh.vertexPositions.push_back(gaussFunction(h, i - 0.5f, j - 0.5f, r / 2) * 0.1f);

			currentHeight = gaussFunction(h, i, j, r / 2) * 0.1f;
			if (currentHeight < 0.6f) {
				texture = "grass";
			}
			else if (currentHeight < 1.4f) {
				texture = "stone";
			}
			else {
				texture = "snow";
			}

			getTexturecoords(t1, texture);
			getTexturecoords(t2, texture);
			getTexturecoords(t3, texture);
			getTexturecoords(t4, texture);

			addRelativetoTexture(t1, 0.0f, 0.0f);
			addRelativetoTexture(t2, 1.0f, 0.0f);
			addRelativetoTexture(t3, 0.0f, 1.0f);
			addRelativetoTexture(t4, 1.0f, 1.0f);

			addTextures(t1, t2, t3, &mountainMesh);
			addTextures(t2, t3, t4, &mountainMesh);

			addIndices(index, index + 1, index + 2, &mountainMesh);
			addIndices(index + 3, index + 4, index + 5, &mountainMesh);

			index += 6;
		}
	}
	return mountainMesh;
}

Model getMountainModel(float x, float y, float h, float r) {
	Mesh mountainMesh = createMountainMesh(h, r);
	translateMesh(x*0.1f, y*0.1f, -0.4f, &mountainMesh);
	Model mountainModel(mountainMesh);
	return mountainModel;
}

void addMountainModel(float x, float y, float h, float r, Renderer* renderer) {
	auto mountainModel = new Model;
	*mountainModel = getMountainModel(x, y, h, r);
	renderer->addModel(mountainModel);
}

float gaussFunction(float peak, float x, float y, float deviation) {
	return peak * exp(-1 * (x * x + y * y) / (2 * deviation * deviation));
}