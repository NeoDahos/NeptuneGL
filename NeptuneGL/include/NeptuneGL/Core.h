#ifndef CORE_H
#define CORE_H

namespace nep
{
	class Core abstract
	{
	public:
		static void EnsureGLInit();

	private:
		static void ErrorCallback(int _code, const char* _message);
		static void InitGLFW();
		static bool InitGLEW();

		static bool s_isGLInit;
	};
}

#endif // CORE_H