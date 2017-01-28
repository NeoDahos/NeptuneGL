#include <NeptuneGL\ContextSettings.h>

namespace nep
{
	ContextSettings::ContextSettings() : m_majorVersion(3), m_minorVersion(3), m_profile(OpenGLProfile::CoreProfile)
	{
	}

	ContextSettings::ContextSettings(int _majorVersion, int _minorVersion, OpenGLProfile _profile) : m_majorVersion(_majorVersion), m_minorVersion(_minorVersion), m_profile(_profile)
	{
	}
}