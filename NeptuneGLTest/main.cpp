#include <NeptuneGL\Core.h>
#include <NeptuneGL\Window.h>

int main()
{
	nep::Window window(nep::VideoMode(800, 600), "Test");

	/*int width, height;
	glfwGetFramebufferSize(window, &width, &height);*/

	glViewport(0, 0, 800, 600);

	while (!window.ShouldClose())
	{
		glfwPollEvents();
		window.Display();
	}

	return 0;
}