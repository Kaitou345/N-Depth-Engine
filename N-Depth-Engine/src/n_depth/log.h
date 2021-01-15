#pragma once

#include "core.h"
#include <spdlog/spdlog.h>
#include <memory>

namespace ND
{
	class ND_API Log
	{
	public:

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& Get_Core_Logger() { return s_core_logger; }
		inline static std::shared_ptr<spdlog::logger>& Get_Client_Logger() { return s_client_logger; }


	private:
		static std::shared_ptr<spdlog::logger> s_core_logger;
		static std::shared_ptr<spdlog::logger> s_client_logger;

	};
}


#ifdef ND_DEBUG_BUILD
// Core log macros
#define ND_CORE_ERROR(...)     ND::Log::Get_Core_Logger()->error(__VA_ARGS__)
#define ND_CORE_WARN(...)      ND::Log::Get_Core_Logger()->warn(__VA_ARGS__)
#define ND_CORE_INFO(...)      ND::Log::Get_Core_Logger()->info(__VA_ARGS__)

#define ND_ERROR(...)          ND::Log::Get_Client_Logger()->error(__VA_ARGS__)
#define ND_WARN(...)           ND::Log::Get_Client_Logger()->warn(__VA_ARGS__)
#define ND_INFO(...)           ND::Log::Get_Client_Logger()->info(__VA_ARGS__)

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

