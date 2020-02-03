#ifndef RENDERER_H_INCLUDED
#define RENDERER_H_INCLUDED

#include "camera.h"
#include "window.h"
#include "shader.h"
//#include "renderInfo.h"
#include "GL.h"

struct RenderInfo;

class Renderer {
public:
	Renderer() {
		m_shader = Shader("standard.vert", "standard.frag");
	}

	void finishRender(Window window, Camera camera);

private:

	bool m_drawBox = false;
	Shader m_shader;
	
	std::vector<const RenderInfo*> m_meshes;
};

#endif // !RENDERER_H_INCLUDED
