#ifdef	FLIPPER_PLATFORM_WINDOWS
	#ifdef FLIPPER_BUILD_DLL
		#define FLIPPER_API _declspec(dllexport)
	#else
		#define FLIPPER_API _declspec(dllimport)
	#endif
#endif