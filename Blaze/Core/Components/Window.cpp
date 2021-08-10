#include "Blaze.h"

void framebuffer_size_callback(GLFWwindow *window, int width, int height);

namespace Blaze
{
	Window::Window(const char *name)
	{
		if (!glfwInit())
			exit(-1);

		const GLFWvidmode *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		this->width = mode->width;
		this->height = mode->height;

		this->handle = glfwCreateWindow(this->width, this->height, name, glfwGetPrimaryMonitor(), NULL);

		if (!this->handle)
			exit(-1);

		glfwMakeContextCurrent(this->handle);
		glfwSetFramebufferSizeCallback(this->handle, framebuffer_size_callback);
	}

	bool Window::ShouldClose()
	{
		return (glfwWindowShouldClose(this->handle));
	}

	Window::~Window()
	{
		glfwDestroyWindow(this->handle);
	}
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	glViewport(0, 0, width, height);
}
