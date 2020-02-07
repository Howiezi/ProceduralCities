#pragma once
#include "GLFW/glfw3.h"

#include <iostream>
//https://github.com/Saikedo/CPP-OpenGL-3D-Game-Engine/tree/master/Saik%20Engine

class Window {
public:
	Window() = default;
	Window(const int width = 800, const int height = 600, const char* title = "Default");
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