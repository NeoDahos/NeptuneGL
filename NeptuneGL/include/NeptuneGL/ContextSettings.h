#ifndef CONTEXT_SETTINGS_H
#define CONTEXT_SETTINGS_H

namespace nep
{
	class ContextSettings
	{
	public:
		enum OpenGLProfile { DefaultProfile = 0, CoreProfile};

		ContextSettings();
		ContextSettings(int _majorVersion, int _minorVersion, OpenGLProfile _profile = OpenGLProfile::CoreProfile);

	public:
		int m_majorVersion;
		int m_minorVersion;
		OpenGLProfile m_profile;
	};
}

#endif // CONTEXT_SETTINGS_H