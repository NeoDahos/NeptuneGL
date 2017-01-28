#include <NeptuneGL\Core.h>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdio.h>

#include <NeptuneGL\Window.h>

namespace nep
{
	bool Core::s_isGLInit = false;

	void Core::ErrorCallback(int _code, const char* _message)
	{
		printf("Error %d : %s.\n", _code, _message);
	}

	void Core::EnsureGLInit()
	{
		if (s_isGLInit)
			return;

		InitGLFW();
	}

	void Core::InitGLFW()
	{
		glfwSetErrorCallback(Core::ErrorCallback);

		if (glfwInit() == GL_FALSE)
		{
			printf("Failed to initialize GLFW\n");
			return;
		}
		printf("GLFW initialized.\n");

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_VISIBLE, GL_FALSE);

		GLFWwindow * window = glfwCreateWindow(320, 240, "Dummy", nullptr, nullptr);
		if (window == nullptr)
		{
			printf("Failed to create dummy window.\n");
			glfwTerminate();
			return;
		}
		glfwMakeContextCurrent(window);

		if (!InitGLEW())
		{
			printf("Failed to initialize GLEW\n");
			glfwTerminate();
			return;
		}

		printf("GLEW initialized.\n");
		glfwDestroyWindow(window);

		s_isGLInit = true;
	}

	bool Core::InitGLEW()
	{
		glewExperimental = GL_TRUE;
		GLenum status = glewInit();

		if (status != GLEW_OK)
		{
			printf("Failed to initialize GLEW, %s.\n", glewGetErrorString(status));
			return false;
		}

		return true;
	}
}