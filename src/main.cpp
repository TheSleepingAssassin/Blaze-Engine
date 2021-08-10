#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Blaze/Blaze.h"

int main(void)
{
	Blaze::Window win("Window");

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		return -1;

	Blaze::GameObject cube(glm::vec3(0.0f, 0.0f, 0.0f), Blaze::TAGS::CUBE);
	Blaze::GameObject plane(glm::vec3(0.0f, -5.0f, 0.0f), Blaze::TAGS::PLANE);
	plane.mesh->SetColor({1.0f, 1.0f, 0.0f, 1.0f});

	glm::mat4 proj = glm::perspective(glm::radians(90.0f), (float)win.width / (float)win.height, 0.1f, 1000.0f);
	cube.mesh->shader->SetMat4(proj, "proj");
	plane.mesh->shader->SetMat4(proj, "proj");

	while (!win.ShouldClose())
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glm::mat4 viewRot = glm::toMat4(glm::quat(glm::vec3(0.0f, 0.0f, 0.0f)));
		glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -10.0f)) * viewRot;
		cube.mesh->shader->SetMat4(view, "view");
		plane.mesh->shader->SetMat4(view, "view");

		cube.transform.Rotation = glm::vec3(glfwGetTime() * 5.0f);
		cube.mesh->shader->SetMat4(cube.transform.GetTransform(), "model");

		plane.transform.Scale = {10.0f, 10.0f, 10.0f};
		plane.mesh->shader->SetMat4(plane.transform.GetTransform(), "model");

		cube.Draw();
		plane.Draw();

		glfwSwapBuffers(win.handle);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
