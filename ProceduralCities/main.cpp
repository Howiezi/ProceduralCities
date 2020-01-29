#pragma once
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>

#include "camera.h"
#include "window.h"
#include "shader.h"
#include "application.h"

Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

// settings
const unsigned SCR_WIDTH = 800;
const unsigned SCR_HEIGHT = 600;
const char* title = "ProceduralCities";

// camera
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;

void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

int main() {

	Window window(SCR_WIDTH, SCR_HEIGHT, title);

	// glfw: initialize and configure
	// ------------------------------
	glfwSetCursorPosCallback(window.getWindow(), mouse_callback);
	glfwSetScrollCallback(window.getWindow(), scroll_callback);

	glfwSetInputMode(window.getWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// build and compile our shader program
	// ------------------------------------
	Shader ourShader("standard.vert", "standard.frag");

	Application app(window);

	app.runLoop();

	return 0;
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

	lastX = xpos;
	lastY = ypos;

	camera.ProcessMouseMovement(xoffset, yoffset);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.ProcessMouseScroll(yoffset);
}