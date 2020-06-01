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

Mesh createSphereMesh(float r, int subdivision, const std::string& texture);
Model getSphereModel(float x,float y,float z,float r, const std::string& texture);
void addSphereModel(float x, float y, float z, float r, Renderer* renderer, const std::string& texture);

void translateMesh(float x, float y, float z, Mesh* mesh);

void subdivideSphere(int subdivision, Mesh* sphere, float r);
void addVertices(const float v1[3], const float v2[3], const float v3[3], Mesh* mesh);
void addIndices(const unsigned int i1, const unsigned int i2, const unsigned int i3, Mesh* mesh);
void addTextures(const float t1[2], const float t2[2], const float t3[2], Mesh* mesh);
void computeHalfVertex(const float v1[3], const float v2[3], float newV[3], float radius);

Mesh createCylinderMesh(float r, float h, const std::string& texture);
Model getCylinderModel(float x, float y, float z, float r, float h, const std::string& texture);
void addCylinderModel(float x, float y, float z, float r, float h, Renderer* renderer, const std::string& texture);

Mesh createCubeMesh(float l, const std::string& texture);
Model getCubeModel(float x, float y, float z, float l, const std::string& texture);
void addCubeModel(float x, float y, float z, float l, Renderer* renderer, const std::string& texture);

Mesh createTorusMesh(float r1, float r2, const std::string& texture);
Model getTorusModel(float x, float y, float z, float r1, float r2, const std::string& texture);
void addTorusModel(float x, float y, float z, float r1, float r2, Renderer* renderer, const std::string& texture);

Mesh createConicalMesh(float rupp, float rdown, float h, const std::string& texture);
Model getConicalModel(float x, float y, float z, float rupp, float rdown, float h, const std::string& texture);
void addConicalModel(float x, float y, float z, float rupp, float rdown, float h, Renderer* renderer, const std::string& texture);

Mesh createCuboidMesh(float l, float w, float h, const std::string& texture);
Model getCuboidModel(float x, float y, float z, float l, float w, float h, const std::string& texture);
void addCuboidModel(float x, float y, float z, float l, float w, float h, Renderer* renderer, const std::string& texture);

Mesh createPyramidMesh(float r, const std::string& texture);
Model getPyramidModel(float x, float y, float z, float r, const std::string& texture);
void addPyramidModel(float x, float y, float z, float r, Renderer* renderer, const std::string& texture);

void createRoad(int x1, int y1, int x2, int y2, Renderer* renderer, const std::string& texture);
void createRoadBetter(int x1, int y1, int x2, int y2, Renderer* renderer, const std::string& texture);
Mesh createRoadMesh(int* xcoords, int* ycoords, int size, const std::string& texture);
Model getRoadModel(int* xcoords, int* ycoords, int size, const std::string& texture);
void addRoadModel(int* xcoords, int* ycoords, int size, Renderer* renderer, const std::string& texture);

Mesh createMountainMesh(float h, float r);
Model getMountainModel(float x, float y, float h, float r);
void addMountainModel(float x, float y, float h, float r, Renderer* renderer);
float gaussFunction(float peak, float x, float y, float deviation);

#endif // !OBJECTS_H_INCLUDED
