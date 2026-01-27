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

#define BIT(x) (1 << x)