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
		m_shader.use();
		m_shader.setInt("textureSample", 0);
		l_shader = Shader("color.vert", "color.frag");
		l_shader.use();
		m_shader.setInt("textureSample", 0);
	}

	Renderer(const std::string &type);

	void finishRender(GLFWwindow *window, Camera *camera);

	void addModel(Model* model);

	void setLineMode(bool mode) {
		lineMode = mode;
	}

private:

	Shader m_shader;
	Shader l_shader;

	bool lineMode = false;
	
	std::vector<const RenderInfo*> m_models;
};

#endif // !RENDERER_H_INCLUDED
