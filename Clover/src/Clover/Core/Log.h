#pragma once

#include <spdlog/spdlog.h>

#include "Core.h"

namespace Clover {
	class CLOVER_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// CORE Log Macros

#define CLOVER_CORE_TRACE(...) ::Clover::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CLOVER_CORE_INFO(...)  ::Clover::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CLOVER_CORE_WARN(...)  ::Clover::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CLOVER_CORE_ERROR(...) ::Clover::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CLOVER_CORE_FATAL(...) ::Clover::Log::GetCoreLogger()->critical(__VA_ARGS__)

// CLIENT Log Macros

#define CLOVER_TRACE(...)      ::Clover::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CLOVER_INFO(...)       ::Clover::Log::GetClientLogger()->info(__VA_ARGS__)
#define CLOVER_WARN(...)       ::Clover::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CLOVER_ERROR(...)      ::Clover::Log::GetClientLogger()->error(__VA_ARGS__)
#define CLOVER_FATAL(...)      ::Clover::Log::GetClientLogger()->critical(__VA_ARGS__)