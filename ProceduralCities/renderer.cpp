#include "renderer.h"
#include "matrixTransformations.h"

float f = 0;
float it = 0.0001;

void Renderer::finishRender(GLFWwindow *window, Camera *camera) {
	//f += it;

	if (f > 1 || f < 0) {
		it *= -1;
	}
	//std::cout << f << std::endl;

	glClearColor(0.0f+f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDisable(GL_BLEND);
	glDisable(GL_CULL_FACE);
	//std::cout << "fff" << std::endl;
	m_shader.use();
	
	m_shader.setMat4("projection", getProjectionMatrix(camera));
	m_shader.setMat4("view", getViewMatrix(camera));
	m_shader.setMat4("model", getModelMatrix());

	for (int mesh = 0; mesh < m_models.size();mesh++) {
		GL::bindVAO(m_models[mesh]->vao);
		GL::drawElements(m_models[mesh]->indicesCount);
	}

}

void Renderer::addModel(Model* model) {
	m_models.push_back(&model->getRenderInfo());
}