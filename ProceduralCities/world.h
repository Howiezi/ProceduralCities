#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

#include "ppm.h"
#include "mesh.h"
#include "model.h"
#include "renderer.h"

WorldMesh createWorldFromFile(const std::string& fname);
Model getWorldModelFromFile(const std::string& fname);
void addWorldModelFromFile(const std::string& fname, Renderer* renderer);

void readRoadFile(const std::string& fname, WorldMesh* world);
void createRoad(int x1, int y1, int x2, int y2, WorldMesh* world);
int computeMiddle(int x1, int x2);


#endif // !WORLD_H_INCLUDED