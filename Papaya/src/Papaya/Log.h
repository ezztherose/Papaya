#pragma once

#include <memory>
#include <memory.h>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Papaya
{
	class PAPAYA_API Log
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

// MARCROS for Core-logging
#define PAPY_CORE_TRACE(...)    ::Papaya::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PAPY_CORE_INFO(...)     ::Papaya::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PAPY_CORE_WARN(...)     ::Papaya::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PAPY_CORE_ERROR(...)    ::Papaya::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PAPY_CORE_FATAL(...)    ::Papaya::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// MARCROS for Client-logging
#define PAPY_TRACE(...)         ::Papaya::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PAPY_INFO(...)          ::Papaya::Log::GetClientLogger()->info(__VA_ARGS__)
#define PAPY_WARN(...)          ::Papaya::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PAPY_ERROR(...)         ::Papaya::Log::GetClientLogger()->error(__VA_ARGS__)
#define PAPY_FATAL(...)         ::Papaya::Log::GetClientLogger()->fatal(__VA_ARGS__)