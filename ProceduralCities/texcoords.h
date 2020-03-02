#ifndef TEXCOORDS_H_INCLUDED
#define TEXCOORDE_H_INCLUDED

#include <string>

void getTexturecoords(float* a, const std::string& tname);
// xshift and yshift should be between 0 and 1
void addRelativetoTexture(float* a, float xshift, float yshift);

#endif // !TEXCOORDS_H_INCLUDED