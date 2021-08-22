#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Blaze/Blaze.h"

int main(void)
{
	Blaze::Window win("Window");
	Blaze::Renderer renderer(win.width, win.height);
	Blaze::CamTransform cam;

	Blaze::GameObject cube(glm::vec3(0.0f, 0.0f, 0.0f), Blaze::TAGS::CUBE);
	renderer.AddObject(&cube);
	Blaze::GameObject plane(glm::vec3(0.0f, -5.0f, 0.0f), Blaze::TAGS::PLANE);
	renderer.AddObject(&plane);
	plane.mesh->SetColor({1.0f, 1.0f, 0.0f, 1.0f});
	renderer.Init(&cam);

	while (!win.ShouldClose())
	{
		glClear(GL_COLOR_BUFFER_BIT);

		cam.Translation = {0, 0, -10};

		cube.transform.Rotation = glm::vec3(glfwGetTime() * 5.0f);
		plane.transform.Scale = {10.0f, 10.0f, 10.0f};

		renderer.Draw();

		glfwSwapBuffers(win.handle);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
