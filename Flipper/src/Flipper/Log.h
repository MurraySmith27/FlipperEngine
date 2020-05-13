#pragma once

#include "flpch.h"
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Flipper {
	class FLIPPER_API Log
	{

	private:

		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	public:

		static void Init();

		//Return a shared pointer reference to the core logger.
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	};

//core logging macros
#define FLIPPER_CORE_INFO(...)    ::Flipper::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FLIPPER_CORE_WARNING(...) ::Flipper::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FLIPPER_CORE_ERROR(...)   ::Flipper::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FLIPPER_CORE_TRACE(...)   ::Flipper::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FLIPPER_CORE_FATAL(...)   ::Flipper::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//client logging macros
#define FLIPPER_INFO(...)    ::Flipper::Log::GetClientLogger()->info(__VA_ARGS__)
#define FLIPPER_WARNING(...) ::Flipper::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FLIPPER_ERROR(...)   ::Flipper::Log::GetClientLogger()->error(__VA_ARGS__)
#define FLIPPER_TRACE(...)   ::Flipper::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FLIPPER_FATAL(...)   ::Flipper::Log::GetClientLogger()->fatal(__VA_ARGS__)
}


