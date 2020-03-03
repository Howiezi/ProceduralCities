#ifndef OBJECTS_H_INCLUDED
#define OBJECTS_H_INCLUDED

#include "model.h"
#include "renderer.h"

Mesh getTreeMesh(float x, float y);
Mesh getBranchMesh(float x, float y);
Model getTreeModel(float x, float y);
Model getBranchModel(float x, float y);
void addTreeModel(float x, float y, Renderer* renderer);

// change this function when adding more model functionality
void readModelsTextfile(const std::string& fname, Renderer* renderer);

Mesh createSphereMesh(float r, int subdivision);
Model getSphereModel(float x,float y,float z,float r);
void addSphereModel(float x, float y, float z, float r, Renderer* renderer);

void translateMesh(float x, float y, float z, Mesh* mesh);

void subdivideSphere(int subdivision, Mesh* sphere, float r);
void addVertices(const float v1[3], const float v2[3], const float v3[3], Mesh* mesh);
void addIndices(const unsigned int i1, const unsigned int i2, const unsigned int i3, Mesh* mesh);
void addTextures(const float t1[2], const float t2[2], const float t3[2], Mesh* mesh);
void computeHalfVertex(const float v1[3], const float v2[3], float newV[3], float radius);

Mesh createCylinderMesh(float r, float h);
Model getCylinderModel(float x, float y, float z, float r, float h);
void addCylinderModel(float x, float y, float z, float r, float h, Renderer* renderer);

Mesh createCubeMesh(float l);
Model getCubeModel(float x, float y, float z, float l);
void addCubeModel(float x, float y, float z, float l, Renderer* renderer);

Mesh createTorusMesh(float rinn, float rout);
Model getTorusModel(float x, float y, float z, float rinn, float rout);
void addTorusModel(float x, float y, float z, float rinn, float rout, Renderer* renderer);

Mesh createConicalMesh(float rupp, float rdown, float h);
Model getConicalModel(float x, float y, float z, float rupp, float rdown, float h);
void addConicalModel(float x, float y, float z, float rupp, float rdown, float h, Renderer* renderer);

Mesh createCuboidMesh(float l, float w, float h);
Model getCuboidModel(float x, float y, float z, float l, float w, float h);
void addCuboidModel(float x, float y, float z, float l, float w, float h, Renderer* renderer);

Mesh createPyramidMesh(float r);
Model getPyramidModel(float x, float y, float z, float r);
void addPyramidModel(float x, float y, float z, float r, Renderer* renderer);

#endif // !OBJECTS_H_INCLUDED
