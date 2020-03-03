#include "objects.h"
#include "texcoords.h"
#include <iostream>

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

		if (!(iss >> type)) { break; }
		
		if (type == "sphere") {
			float x, y, z, r;
			if (!(iss >> x >> y >> z >> r)) { break; }

			addSphereModel(x, y, z, r, renderer);

		}
		else if (type == "tree") {
			float x, y;
			if (!(iss >> x >> y)) { break; }

			addTreeModel(x, y, renderer);
		}
		else if (type == "cylinder") {
			float x, y, z, r, h;
			if (!(iss >> x >> y >> z >> r >> h)) { break; }

			addCylinderModel(x, y, z, r, h, renderer);
		}
		else if (type == "cube") {
			float x, y, z, l;
			if (!(iss >> x >> y >> z >> l)) { break; }

			addCubeModel(x, y, z, l, renderer);
		}
		else if (type == "torus") {
			float x, y, z, r1, r2;
			if (!(iss >> x >> y >> z >> r1 >> r2)) { break; }

			addTorusModel(x, y, z, r1, r2, renderer);
		}
		else if (type == "conical") {
			float x, y, z, rupp, rdown, h;
			if (!(iss >> x >> y >> z >> rupp >> rdown >> h)) { break; }

			addConicalModel(x, y, z, rupp, rdown, h, renderer);
		}
		else if (type == "cuboid") {
			float x, y, z, l, w, h;
			if (!(iss >> x >> y >> z >> l >> w >> h)) { break; }

			addCuboidModel(x, y, z, l, w, h, renderer);
		}
		else if (type == "pyramid") {
			float x, y, z, r;
			if (!(iss >> x >> y >> z >> r)) { break; }

			addPyramidModel(x, y, z, r, renderer);
		}
		else {
			continue;
		}

	}
}

Mesh createSphereMesh(float r, int subdivision) {
	// Constants for angle calculations
	const float PI = 3.1415926f;
	const float H_ANGLE = PI / 180 * 72;
	const float V_ANGLE = atanf(1.0f / 2);

	Mesh sphere;

	for (int i = 0; i < 6; i++) {
		// The top vertex of the sphere
		sphere.vertexPositions.push_back(0);
		sphere.vertexPositions.push_back(0);
		sphere.vertexPositions.push_back(r);

		sphere.textureCoords.push_back((1.0f+2.0f*i) * 46 / 5120 + 0.1f);
		sphere.textureCoords.push_back(0.0f * 170 / 5120 + 0.9f);

		// Vertexes of upper layer
		sphere.vertexPositions.push_back(r * cosf(V_ANGLE) * cosf(H_ANGLE * i));
		sphere.vertexPositions.push_back(r * cosf(V_ANGLE) * sinf(H_ANGLE * i));
		sphere.vertexPositions.push_back(r * sinf(V_ANGLE));

		sphere.textureCoords.push_back(2.0f * i * 46 / 5120 + 0.1f);
		sphere.textureCoords.push_back(170.0f / 5120 + 0.9f);
		
		// Vertextes of bottom layer
		sphere.vertexPositions.push_back(r * cosf(V_ANGLE) * cosf(H_ANGLE * i + PI / 5));
		sphere.vertexPositions.push_back(r * cosf(V_ANGLE) * sinf(H_ANGLE * i + PI / 5));
		sphere.vertexPositions.push_back((-1) * r * sinf(V_ANGLE));

		sphere.textureCoords.push_back((2.0f * i + 1) * 46 / 5120 + 0.1f);
		sphere.textureCoords.push_back(2.0f * 170 / 5120 + 0.9f);

		// Bottom vertex of the sphere
		sphere.vertexPositions.push_back(0);
		sphere.vertexPositions.push_back(0);
		sphere.vertexPositions.push_back(-r);

		sphere.textureCoords.push_back((1.0f + 2.0f * i) * 46 / 5120 + 0.1f);
		sphere.textureCoords.push_back(3.0f * 170 / 5120 + 0.9f);

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

Model getSphereModel(float x, float y, float z, float r) {
	Mesh spheremesh = createSphereMesh(r,4);
	translateMesh(x, y, z, &spheremesh);
	Model spheremodel(spheremesh);
	return spheremodel;
}

void addSphereModel(float x,float y,float z, float r, Renderer* renderer) {
	auto sphereModel = new Model;
	*sphereModel = getSphereModel(x,y,z,r);
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

Mesh createCylinderMesh(float r, float h) {
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

		getTexturecoords(t1, "bark");
		getTexturecoords(t2, "bark");
		getTexturecoords(t3, "bark");

		getTexturecoords(t4, "bark");
		getTexturecoords(t5, "bark");
		getTexturecoords(t6, "bark");
		getTexturecoords(t7, "bark");

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

Model getCylinderModel(float x, float y, float z, float r, float h) {
	Mesh cylinderMesh = createCylinderMesh(r, h);
	translateMesh(x, y, z, &cylinderMesh);
	Model cylinderModel(cylinderMesh);
	return cylinderModel;
}

void addCylinderModel(float x, float y, float z, float r, float h, Renderer* renderer) {
	auto cylinderModel = new Model;
	*cylinderModel = getCylinderModel(x, y, z, r, h);
	renderer->addModel(cylinderModel);
}

Mesh createCubeMesh(float l) {
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

	getTexturecoords(t1, "bark");
	getTexturecoords(t2, "bark");
	getTexturecoords(t3, "bark");
	getTexturecoords(t4, "bark");

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

Model getCubeModel(float x, float y, float z, float l) {
	Mesh cubeMesh = createCubeMesh(l);
	translateMesh(x, y, z, &cubeMesh);
	Model cubeModel(cubeMesh);
	return cubeModel;
}

void addCubeModel(float x, float y, float z, float l, Renderer* renderer) {
	auto cubeModel = new Model;
	*cubeModel = getCubeModel(x, y, z, l);
	renderer->addModel(cubeModel);
}

Mesh createTorusMesh(float rinn, float rout) {
	Mesh torus;

	// Constants for angle calculations
	const int SEGMENTS = 24;
	const float PI = 3.1415926f;
	const float H_ANGLE = PI / 180 * 360 / SEGMENTS;
	const float V_ANGLE = atanf(1.0f / 2);

	float nextI[3] = { rinn * cosf(H_ANGLE * 1),rinn * sinf(H_ANGLE * 1),0 };
	float prevI[3] = { rinn * cosf(H_ANGLE * 0),rinn * sinf(H_ANGLE * 0),0 };

	float nextO[3] = { rout * cosf(H_ANGLE * 1),rout * sinf(H_ANGLE * 1),0 };
	float prevO[3] = { rout * cosf(H_ANGLE * 0),rout * sinf(H_ANGLE * 0),0 };

	float nextU[3] = { (rout + rinn) / 2 * cosf(H_ANGLE * 1),(rout + rinn) / 2 * sinf(H_ANGLE * 1),(rout - rinn) / 2 };
	float prevU[3] = { (rout + rinn) / 2 * cosf(H_ANGLE * 0),(rout + rinn) / 2 * sinf(H_ANGLE * 0),(rout - rinn) / 2 };

	float nextD[3] = { (rout + rinn) / 2 * cosf(H_ANGLE * 1),(rout + rinn) / 2 * sinf(H_ANGLE * 1),-(rout - rinn) / 2 };
	float prevD[3] = { (rout + rinn) / 2 * cosf(H_ANGLE * 0),(rout + rinn) / 2 * sinf(H_ANGLE * 0),-(rout - rinn) / 2 };

	int index = 0;

	for (int i = 2; i < SEGMENTS + 2; i++) {
		addVertices(prevU, nextU, prevO, &torus);
		addVertices(nextU, prevO, nextO, &torus);

		addVertices(prevO, nextO, prevD, &torus);
		addVertices(nextO, prevD, nextD, &torus);

		addVertices(prevD, nextD, prevI, &torus);
		addVertices(nextD, prevI, nextI, &torus);

		addVertices(prevI, nextI, prevU, &torus);
		addVertices(nextI, prevU, nextU, &torus);

		float t1[2], t2[2], t3[2], t4[2];

		getTexturecoords(t1, "bark");
		getTexturecoords(t2, "bark");
		getTexturecoords(t3, "bark");
		getTexturecoords(t4, "bark");


		addRelativetoTexture(t1, 0.0f, 0.0f);
		addRelativetoTexture(t2, 1.0f, 0.0f);
		addRelativetoTexture(t3, 0.0f, 1.0f);
		addRelativetoTexture(t4, 1.0f, 1.0f);


		// add 4 new textures
		for (int i = 0; i < 4; i++) {
			addTextures(t3, t4, t1, &torus);
			addTextures(t4, t1, t2, &torus);
		}

		addIndices(index, index + 1, index + 2, &torus);
		addIndices(index + 3, index + 4, index + 5, &torus);
		addIndices(index + 6, index + 7, index + 8, &torus);
		addIndices(index + 9, index + 10, index + 11, &torus);

		addIndices(index + 12, index + 13, index + 14, &torus);
		addIndices(index + 15, index + 16, index + 17, &torus);
		addIndices(index + 18, index + 19, index + 20, &torus);
		addIndices(index + 21, index + 22, index + 23, &torus);

		index += 24;

		prevU[0] = nextU[0];
		prevO[0] = nextO[0];
		prevD[0] = nextD[0];
		prevI[0] = nextI[0];
		prevU[1] = nextU[1];
		prevO[1] = nextO[1];
		prevD[1] = nextD[1];
		prevI[1] = nextI[1];
		nextU[0] = (rout + rinn) / 2 * cosf(H_ANGLE * i);
		nextU[1] = (rout + rinn) / 2 * sinf(H_ANGLE * i);
		nextO[0] = rout * cosf(H_ANGLE * i);
		nextO[1] = rout * sinf(H_ANGLE * i);
		nextD[0] = (rout + rinn) / 2 * cosf(H_ANGLE * i);
		nextD[1] = (rout + rinn) / 2 * sinf(H_ANGLE * i);
		nextI[0] = rinn * cosf(H_ANGLE * i);
		nextI[1] = rinn * sinf(H_ANGLE * i);
	}

	return torus;
}

Model getTorusModel(float x, float y, float z, float rinn, float rout) {
	Mesh torusMesh = createTorusMesh(rinn, rout);
	translateMesh(x, y, z, &torusMesh);
	Model torusModel(torusMesh);
	return torusModel;
}

void addTorusModel(float x, float y, float z, float rinn, float rout, Renderer* renderer) {
	auto torusModel = new Model;
	*torusModel = getTorusModel(x, y, z, rinn, rout);
	renderer->addModel(torusModel);
}

Mesh createConicalMesh(float rupp, float rdown, float h) {
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

		getTexturecoords(t1, "bark");
		getTexturecoords(t2, "bark");
		getTexturecoords(t3, "bark");

		getTexturecoords(t4, "bark");
		getTexturecoords(t5, "bark");
		getTexturecoords(t6, "bark");
		getTexturecoords(t7, "bark");

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

Model getConicalModel(float x, float y, float z, float rupp, float rdown, float h) {
	Mesh conicalMesh = createConicalMesh(rupp, rdown, h);
	translateMesh(x, y, z, &conicalMesh);
	Model conicalModel(conicalMesh);
	return conicalModel;
}

void addConicalModel(float x, float y, float z, float rupp, float rdown, float h, Renderer* renderer) {
	auto conicalModel = new Model;
	*conicalModel = getConicalModel(x, y, z, rupp, rdown, h);
	renderer->addModel(conicalModel);
}

Mesh createCuboidMesh(float l, float w,float h) {
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

	getTexturecoords(t1, "bark");
	getTexturecoords(t2, "bark");
	getTexturecoords(t3, "bark");
	getTexturecoords(t4, "bark");

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

Model getCuboidModel(float x, float y, float z, float l, float w, float h) {
	Mesh cuboidMesh = createCuboidMesh(l, w, h);
	translateMesh(x, y, z, &cuboidMesh);
	Model cuboidModel(cuboidMesh);
	return cuboidModel;
}

void addCuboidModel(float x, float y, float z, float l, float w, float h, Renderer* renderer) {
	auto cuboidModel = new Model;
	*cuboidModel = getCuboidModel(x, y, z, l, w, h);
	renderer->addModel(cuboidModel);
}

Mesh createPyramidMesh(float r) {
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

	getTexturecoords(t1, "bark");
	getTexturecoords(t2, "bark");
	getTexturecoords(t3, "bark");

	addRelativetoTexture(t1, 0.5f, 1.0f);
	addRelativetoTexture(t2, 0.0f, 0.0f);
	addRelativetoTexture(t3, 1.0f, 0.0f);

	for (int i = 0; i < 12; i += 3) {
		addIndices(i, i + 1, i + 2, &pyramid);
		addTextures(t1, t2, t3, &pyramid);
	}

	return pyramid;
}

Model getPyramidModel(float x, float y, float z, float r) {
	Mesh pyramidMesh = createPyramidMesh(r);
	translateMesh(x, y, z, &pyramidMesh);
	Model pyramidModel(pyramidMesh);
	return pyramidModel;
}

void addPyramidModel(float x, float y, float z, float r, Renderer* renderer) {
	auto pyramidModel = new Model;
	*pyramidModel = getPyramidModel(x, y, z, r);
	renderer->addModel(pyramidModel);
}
