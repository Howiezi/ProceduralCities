#include "objects.h"
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