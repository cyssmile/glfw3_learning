#define GLFW_INCLUDE_NONE
#ifdef _WIN32
#include <windows.h>
#endif
#include <iostream>
#include <gl/GL.h>
#include <GLFW/glfw3.h>

int main() {
	GLFWwindow* window;

	// Initialize glfw3
	if (!glfwInit()) {
		return -1;
	}
	// create a window
	window = glfwCreateWindow(640, 480, "hello", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	// make the window cntext
	glfwMakeContextCurrent(window);
	// loop until user closes the window
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
		// render here
		glfwSwapBuffers(window);
		// poll for and process events
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}