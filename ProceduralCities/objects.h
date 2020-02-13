#ifndef OBJECTS_H_INCLUDED
#define OBJECTS_H_INCLUDED

#include "model.h"
#include "renderer.h"

Mesh getTreeMesh(float x, float y);
Mesh getBranchMesh(float x, float y);
Model getTreeModel(float x, float y);
Model getBranchModel(float x, float y);
void addTreeModel(float x, float y, Renderer* renderer);

#endif // !OBJECTS_H_INCLUDED
