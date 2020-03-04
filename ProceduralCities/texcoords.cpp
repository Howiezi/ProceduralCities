#include "texcoords.h"
#include <iostream>

// Change these if the maximum number of textures in the atlas is changed
int ATLASWIDTH = 10;
int ATLASHEIGHT = 10;

// The positions of the textures in the atlas need to remain constant
// relative to the bottom left corner if the size of the atlas is changed

// Add textures to this functions as textures are added to atlas
void getTexturecoords(float* a, const std::string& tname) {
	if (tname == "grass") {
		a[0] = 0.0f / ATLASWIDTH;
		a[1] = 9.0f / ATLASHEIGHT;
	}
	else if (tname == "bark") {
		a[0] = 1.0f / ATLASWIDTH;
		a[1] = 9.0f / ATLASHEIGHT;
	}
	else if (tname == "branch") {
		a[0] = 2.0f / ATLASWIDTH;
		a[1] = 9.0f / ATLASHEIGHT;
	}
	else if (tname == "snow") {
		a[0] = 3.0f / ATLASWIDTH;
		a[1] = 9.0f / ATLASHEIGHT;
	}
	else if (tname == "road") {
		a[0] = 4.0f / ATLASWIDTH;
		a[1] = 9.0f / ATLASHEIGHT;
	}
	else if (tname == "stone") {
		a[0] = 0.0f / ATLASWIDTH;
		a[1] = 8.0f / ATLASHEIGHT;
	}

}


void addRelativetoTexture(float *a, float xshift, float yshift) {
	a[0] += xshift / ATLASWIDTH;
	a[1] += yshift / ATLASHEIGHT;
}