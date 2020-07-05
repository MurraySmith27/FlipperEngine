#ifdef	FLIPPER_PLATFORM_WINDOWS
	#ifdef FLIPPER_BUILD_DLL
		#define FLIPPER_API _declspec(dllexport)
	#else
		#define FLIPPER_API _declspec(dllimport)
	#endif
#endif

#ifdef FLIPPER_ENABLE_ASSERT

	#define FLIPPER_CORE_ASSERT(x, ...) { if(!(x)) {FLIPPER_CORE_ERROR("Flipper Assertion Error: {0}", __VA_ARGS__); __debugbreak();} }
	#define FLIPPER_ASSERT(x, ...)  { if(!(x)) {FLIPPER_ERROR("Flipper Assertion Error: {0}", __VA_ARGS__); __debugbreak();} }

#else
	#define FLIPPER_ASSERT(x, ...)
	#define FLIPPER_CORE_ASSERT(x, ...)
#endif