#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include <vector>

#include "camera.h"
#include "window.h"

class Application {

public:
	Application(Window window) {
		deltaTime = 0.0f;
		lastFrame = 0.0f;
		m_window = window;

	}

	void runLoop();

	Camera& getCamera(){
		return m_camera;
	}

	Window& getWindow() {
		return m_window;
	}

private:

	void processInput(GLFWwindow* window);

	Window m_window;
	Camera m_camera;

	float deltaTime = 0.0f;
	float lastFrame = 0.0f;

};

#endif // !APPLICATION_H_INCLUDED
