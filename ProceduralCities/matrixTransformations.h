#ifndef MATRIXTRANSFORM_H_INCLUDED
#define MATRIXTRANSFORM_H_INCLUDED

#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>

#include "camera.h"
#include "window.h"
#include "mesh.h"

glm::mat4 getProjectionMatrix(Camera camera) {
	glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 150.0f);
	return projection;
}

glm::mat4 getViewMatrix(Camera camera) {
	glm::mat4 view = camera.GetViewMatrix();
	return view;
}

glm::mat4 getModelMatrix() {
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(1.0f, -10.0f, 1.0f));
	model = glm::rotate(model, (float)glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	return model;
}

#endif // !MATRIXTRANSFORM_H_INCLUDED
