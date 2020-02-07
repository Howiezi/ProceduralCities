#ifndef RENDERER_H_INCLUDED
#define RENDERER_H_INCLUDED

#include "camera.h"
#include "shader.h"
//#include "renderInfo.h"
#include "GL.h"
#include "mesh.h"
#include "model.h"
#include "window.h"

class Renderer {
public:
	Renderer() {
		m_shader = Shader("standard.vert", "standard.frag");
	}

	void finishRender(GLFWwindow *window, Camera *camera);

	void addModel(Model model);

private:

	Shader m_shader;
	
	std::vector<const RenderInfo*> m_models;
};

#endif // !RENDERER_H_INCLUDED
