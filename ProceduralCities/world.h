#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

#include "ppm.h"
#include "mesh.h"
#include "model.h"
#include "renderer.h"

WorldMesh createWorldFromFile(const std::string& fname);
Model getWorldModelFromFile(const std::string& fname);
void addWorldModelFromFile(const std::string& fname, Renderer* renderer);


#endif // !WORLD_H_INCLUDED