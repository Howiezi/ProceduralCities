#include "renderer.h"
#include "matrixTransformations.h"

float f = 0;
float it = 0.0001;

Renderer::Renderer(const std::string &type) {
	m_shader = Shader(type + ".vert",type + ".frag");
	m_shader.use();
}

void Renderer::finishRender(GLFWwindow *window, Camera *camera) {
	//f += it;

	if (f > 1 || f < 0) {
		it *= -1;
	}
	//std::cout << f << std::endl;

	glClearColor(0.2f+f, 0.1f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDisable(GL_BLEND);
	glDisable(GL_CULL_FACE);
	//std::cout << "fff" << std::endl;

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	m_shader.use();
	
	m_shader.setMat4("projection", getProjectionMatrix(camera));
	m_shader.setMat4("view", getViewMatrix(camera));
	m_shader.setMat4("model", getModelMatrix());

	for (int mesh = 0; mesh < m_models.size();mesh++) {
		GL::bindVAO(m_models[mesh]->vao);
		GL::drawElements(m_models[mesh]->indicesCount);
	}

	if (lineMode == true) {

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		l_shader.use();

		l_shader.setMat4("projection", getProjectionMatrix(camera));
		l_shader.setMat4("view", getViewMatrix(camera));
		l_shader.setMat4("model", getModelMatrix());

		for (int mesh = 0; mesh < m_models.size(); mesh++) {
			GL::bindVAO(m_models[mesh]->vao);
			GL::drawElements(m_models[mesh]->indicesCount);
		}
	}
}

void Renderer::addModel(Model* model) {
	m_models.push_back(&model->getRenderInfo());
}