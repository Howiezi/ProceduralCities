#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include <vector>

#include "camera.h"
#include "window.h"

class Application {

public:
	Application(GLFWwindow *window, Camera *camera) {
		deltaTime = 0.0f;
		lastFrame = 0.0f;
		m_window = window;
		m_camera = camera;
	}

	void runLoop();

	Camera* getCamera(){
		return m_camera;
	}

	GLFWwindow* getWindow() {
		return m_window;
	}

private:

	void processInput();

	GLFWwindow* m_window;
	Camera* m_camera;

	float deltaTime = 0.0f;
	float lastFrame = 0.0f;

};

#endif // !APPLICATION_H_INCLUDED
