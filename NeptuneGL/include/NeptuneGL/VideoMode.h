#ifndef VIDEO_MODE_H
#define VIDEO_MODE_H

#include <vector>

namespace nep
{
	class VideoMode
	{
	public:
		VideoMode(unsigned int _width, unsigned int _height, unsigned int _bitsPerPixel = 32);

		static VideoMode GetDesktopVideoMode();
		static std::vector<VideoMode> GetValidVideoModes();

	public:
		unsigned int m_width;
		unsigned int m_height;
		unsigned int m_bitsPerPixel;
	};
}

#endif // VIDEO_MODE_H