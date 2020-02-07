#ifndef GLFWFUNCTIONS_H_INCLUDED
#define GLFWFUNCTIONS_H_INCLUDED
#pragma once

#include "camera.h"
#include "GLFW/glfw3.h"

#include <iostream>

void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

void initializeGLFW(GLFWwindow* window, Camera* camera);

#endif // !GLFWFUNCTIONS_H_INCLUDED