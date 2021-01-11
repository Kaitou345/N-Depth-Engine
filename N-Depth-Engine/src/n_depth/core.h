#pragma once

#ifdef ND_PLATFORM_WINDOWS
	#ifdef ND_BUILD_DLL
		#define ND_API __declspec(dllexport)
	#else
		#define ND_API __declspec(dllimport)
	#endif
#else
	#error n_depth only supports windows
#endif

