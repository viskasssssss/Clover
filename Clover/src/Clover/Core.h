#pragma once

#include <memory>

#ifdef CLOVER_PLATFORM_WINDOWS
#if CLOVER_DYNAMIC_LINK
	#ifdef CLOVER_BUILD_DLL
		#define CLOVER_API __declspec(dllexport)
	#else
		#define CLOVER_API __declspec(dllimport)
	#endif
#else
	#define CLOVER_API
#endif
#else
	#error Clover only supports Windows
#endif

#ifdef CLOVER_DEBUG
	#define CLOVER_ENABLE_ASSERTS
#endif

#ifdef CLOVER_ENABLE_ASSERTS
	#define CLOVER_ASSERT(x, ...) { if (!(x)) { CLOVER_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define CLOVER_CORE_ASSERT(x, ...) { if (!(x)) { CLOVER_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define CLOVER_ASSERT(x, ...) 
	#define CLOVER_CORE_ASSERT(x, ...) 
#endif

#define BIT(x) (1 << x)

#define CLOVER_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Clover
{
	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;
}