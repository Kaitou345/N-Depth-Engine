#pragma once

#include "core.h"
#include <spdlog/spdlog.h>
#include <memory>

namespace nd
{
	class ND_API log
	{
	public:

		static void init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_core_logger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_client_logger; }


	private:
		static std::shared_ptr<spdlog::logger> s_core_logger;
		static std::shared_ptr<spdlog::logger> s_client_logger;

	};
}


#ifdef ND_DEBUG_BUILD
// Core log macros
#define ND_CORE_ERROR(...)     nd::log::GetCoreLogger()->error(__VA_ARGS__)
#define ND_CORE_WARN(...)      nd::log::GetCoreLogger()->warn(__VA_ARGS__)
#define ND_CORE_INFO(...)      nd::log::GetCoreLogger()->info(__VA_ARGS__)

// Client log macros
#define ND_ERROR(...)          nd::log::GetCoreLogger()->error(__VA_ARGS__)
#define ND_WARN(...)           nd::log::GetCoreLogger()->warn(__VA_ARGS__)
#define ND_INFO(...)           nd::log::GetCoreLogger()->info(__VA_ARGS__)

#else 
// Core log macros
#define ND_CORE_ERROR(...)
#define ND_CORE_WARN(...) 
#define ND_CORE_INFO(...) 

// Client log macros
#define ND_ERROR(...)     
#define ND_WARN(...)      
#define ND_INFO(...)      
#endif

