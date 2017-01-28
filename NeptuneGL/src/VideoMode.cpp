#include <NeptuneGL\VideoMode.h>

#include <GLFW/glfw3.h>

namespace nep
{
	VideoMode::VideoMode(unsigned int _width, unsigned int _height, unsigned int _bitsPerPixel) : m_width(_width), m_height(_height), m_bitsPerPixel(_bitsPerPixel)
	{
	}

	VideoMode VideoMode::GetDesktopVideoMode()
	{
		GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
		const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);

		return VideoMode(mode->width, mode->height, mode->redBits + mode->greenBits + mode->blueBits);
	}

	std::vector<VideoMode> VideoMode::GetValidVideoModes()
	{
		int count;
		GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
		const GLFWvidmode* modes = glfwGetVideoModes(primaryMonitor, &count);
		std::vector<VideoMode> videoModes;

		for (int i = 0; i < count; i++)
			videoModes.emplace_back(VideoMode(modes[i].width, modes[i].height, modes[i].redBits + modes[i].greenBits + modes[i].blueBits));

		return videoModes;
	}
}