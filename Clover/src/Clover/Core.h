#pragma once

#ifdef CLOVER_PLATFORM_WINDOWS
	#ifdef CLOVER_BUILD_DLL
		#define CLOVER_API __declspec(dllexport)
	#else
		#define CLOVER_API __declspec(dllimport)
	#endif
#else
	#error Clover only supports Windows
#endif

#ifdef CLOVER_ENABLE_ASSERTS
	#define CLOVER_ASSERT(x, ...) { if (!(x)) { CLOVER_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define CLOVER_CORE_ASSERT(x, ...) { if (!(x)) { CLOVER_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define CLOVER_ASSERT(x, ...) 
	#define CLOVER_CORE_ASSERT(x, ...) 
#endif

#define BIT(x) (1 << x)