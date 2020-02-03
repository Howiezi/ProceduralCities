#pragma once
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>
//https://github.com/Saikedo/CPP-OpenGL-3D-Game-Engine/tree/master/Saik%20Engine

// settings
const unsigned SCR_WIDTH = 800;
const unsigned SCR_HEIGHT = 600;

class Window {
public:
	Window() = default;
	Window(const char* title);
	~Window();

	GLFWwindow* getWindow() {
		return window;
	}

	int getWindowWidth() {
		return screenWidth;
	}

	int getWindowHeight() {
		return screenHeight;
	}

	static Window* getWindowInstance() { return instance; }

private:
	static Window* instance;
	GLFWwindow* window;
	int screenWidth;
	int screenHeight;
};