#ifndef WINDOW_H
#define WINDOW_H

#include <NeptuneGL\ContextSettings.h>
#include <NeptuneGL\VideoMode.h>

#include <GLFW/glfw3.h>

namespace nep
{
	class Window
	{
	public:
		Window();
		Window(VideoMode _videoMode, const char * _title, ContextSettings _settings = ContextSettings());

		void Create(VideoMode _videoMode, const char * _title, ContextSettings _settings = ContextSettings());
		void Close();
		void Destroy();

		void Display();

		bool ShouldClose() const;

	private:
		GLFWwindow * m_window;
		bool m_isCurrentContext;
	};
}
#endif // WINDOW_H