#include <iostream>
#include <fstream>

#include "Main.h"

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(1080, 720, "CMake Trial", NULL, NULL);
	if (!window)
	{
		std::cout << "Failed to create window!" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to Initialize Glad!" << std::endl;
		glfwTerminate();
		return -1;
	}

	std::ifstream is;
	is.open("assets/meshes/teapot.obj");
	if (!is)
		std::cout << "[-] Failed to open file!" << std::endl;
	else
		std::cout << "[+] FILE OPENED SUCCESSFULLY!" << std::endl;
	is.close();

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.2f, 0.6f, 0.8f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}