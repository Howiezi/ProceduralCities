#pragma once
#include <iostream>

#include "application.h"
#include "glfwFunctions.h"
#include "window.h"

int main() {

	Window window(800,600,"Procedural Cities");

	Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

	initializeGLFW(window.getWindow(),&camera);

	Application app(window.getWindow(),&camera);

	app.runLoop();

	return 0;
}