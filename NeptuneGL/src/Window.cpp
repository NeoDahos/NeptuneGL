#include <NeptuneGL\Window.h>
#include <NeptuneGL\Core.h>

namespace nep
{
	Window::Window()
	{
		m_window = nullptr;
		m_isCurrentContext = false;
	}

	Window::Window(VideoMode _videoMode, const char * _title, ContextSettings _settings)
	{
		Create(_videoMode, _title, _settings);
	}

	void Window::Create(VideoMode _videoMode, const char * _title, ContextSettings _settings)
	{
		Core::EnsureGLInit();

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, _settings.m_majorVersion);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, _settings.m_minorVersion);

		if(_settings.m_majorVersion < 3 || (_settings.m_majorVersion == 3 && _settings.m_minorVersion < 3) || _settings.m_profile != ContextSettings::OpenGLProfile::CoreProfile)
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);
		else
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		const unsigned int bitsPerColor = _videoMode.m_bitsPerPixel / 4;
		glfwWindowHint(GLFW_RED_BITS, bitsPerColor);
		glfwWindowHint(GLFW_GREEN_BITS, bitsPerColor);
		glfwWindowHint(GLFW_BLUE_BITS, bitsPerColor);
		glfwWindowHint(GLFW_ALPHA_BITS, bitsPerColor);

		glfwWindowHint(GLFW_VISIBLE, GL_TRUE);

		m_window = glfwCreateWindow(_videoMode.m_width, _videoMode.m_height, _title, nullptr, nullptr);
		if (m_window == nullptr)
		{
			printf("Failed to create window.\n");
			m_isCurrentContext = false;
			glfwTerminate();
			return;
		}

		glfwMakeContextCurrent(m_window);
		m_isCurrentContext = true;
	}

	void Window::Close()
	{
		glfwSetWindowShouldClose(m_window, GL_TRUE);
	}

	void Window::Destroy()
	{
		glfwDestroyWindow(m_window);
		m_isCurrentContext = false;
	}

	void Window::Display()
	{
		glfwSwapBuffers(m_window);
	}

	bool Window::ShouldClose() const
	{
		return glfwWindowShouldClose(m_window) == GL_TRUE ? true : false;
	}
}