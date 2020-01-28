#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include <vector>

#include "camera.h"
#include "window.h"

class Application {

public:
	Application();

	void runLoop();

	Camera& getCamera(){
		return m_camera;
	}

	const Window& getWindow() const{
		return m_window;
	}

private:

	Window m_window;
	Camera m_camera;

};

#endif // !APPLICATION_H_INCLUDED
