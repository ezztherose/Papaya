#pragma once

#ifdef PAPY_PLATFORM_WINDOWS
	#ifdef PAPY_BUILD_DLL
		#define PAPAYA_API __declspec(dllexport)
	#else
		#define PAPAYA_API __declspec(dllimport)
	#endif
#else
	#error Papaya only support Windows
#endif // PAPY_PLATFORM_WINDOWS
