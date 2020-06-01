#ifndef MESHUTILITY_H_INCLUDED
#define MESHUTILITY_H_INCLUDED

#include "mesh.h"

void changeHeightSquareLess(Mesh* mesh, float x, float y, float z);
void changeHeightWorldMesh(WorldMesh* mesh, float x, float y, float z);
void changeTextureWorldMesh(WorldMesh* mesh, float x, float y);
void createMountain(WorldMesh* mesh, float x, float y, float height, int radius);

#endif // !MESHUTILITY_H_INCLUDED
