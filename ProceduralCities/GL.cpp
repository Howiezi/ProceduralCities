#include "GL.h"
#include <iostream>

void GL::drawElements(GLuint indicesCount) noexcept {
	//std::cout << indicesCount << std::endl;
	glDrawElements(GL_TRIANGLES, indicesCount, GL_UNSIGNED_INT, nullptr);
}

void GL::bindVAO(GLuint vao) noexcept {
	//std::cout << vao << std::endl;
	glBindVertexArray(vao);
}