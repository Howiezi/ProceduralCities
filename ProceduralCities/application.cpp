#include "application.h"
#include "renderer.h"
#include "squareMesh.h"
#include "objects.h"
#include "meshUtility.h"
#include "world.h"

void Application::runLoop(){
	Renderer mRender;
	//addWorldModelFromFile("heightmap.ppm",&mRender);
	addSquareModel(100,&mRender);
	//addSquareModelLess(11, &mRender);

	readModelsTextfile("Models.txt",&mRender);

	//addTreeModel(0.6f, 0.6f, &mRender);
	Texture btex("Textures/atlas.png");

	// Uncomment for polygon lines
	// mRender.setLineMode(true);
	while (!glfwWindowShouldClose(m_window)) {
		// per-frame time logic
			// --------------------
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		// input
		// -----
		processInput();

		// render
		// ------
		mRender.finishRender(m_window, m_camera);

		// glfw: swap buffers and pholl IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}

	// glfw: terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	glfwTerminate();
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void Application::processInput()
{
	if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(m_window, true);

	if (glfwGetKey(m_window, GLFW_KEY_W) == GLFW_PRESS)
		m_camera->ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(m_window, GLFW_KEY_S) == GLFW_PRESS)
		m_camera->ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(m_window, GLFW_KEY_A) == GLFW_PRESS)
		m_camera->ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(m_window, GLFW_KEY_D) == GLFW_PRESS)
		m_camera->ProcessKeyboard(RIGHT, deltaTime);
}