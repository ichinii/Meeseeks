#ifndef UTIL_PLATFORM_H
#define UTIL_PLATFORM_H

#include <stdio.h>

#if !defined(DEBUG) && defined(NDEBUG)
#define DEBUG
#endif

#if defined(WINDOWS)
	#include <direct.h>
	#define GetWorkingDir _getcwd
#elif
	#include <unistd.h>
	#define GetWorkingDir getcwd
#endif

#endif
