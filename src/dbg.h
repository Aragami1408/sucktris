#ifndef DBG_H
#define DBG_H

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>

void tprintf(const char *fmt, ...);

#ifdef NDEBUG
	#define log_debug(fmt, ...) 
	#define log_err(fmt, ...) 
	#define log_warn(fmt, ...) 
	#define log_info(fmt, ...) 
#else
	#define log_debug(fmt, ...) tprintf("[DEBUG] %10s:%10d:%15s(): " fmt, __FILE__,  __LINE__, __func__,## __VA_ARGS__);
	#define log_err(fmt, ...) tprintf("[\033[0;31mERROR\033[0m] %10s:%10d:%15s(): " fmt, __FILE__,  __LINE__, __func__,## __VA_ARGS__);
	#define log_warn(fmt, ...) tprintf("[\033[0;33mWARNING\033[0m] %10s:%10d:%15s(): " fmt, __FILE__,  __LINE__, __func__,## __VA_ARGS__);
	#define log_info(fmt, ...) tprintf("[\033[0;32mINFO\033[0m] %10s:%10d:%15s(): " fmt, __FILE__,  __LINE__, __func__,## __VA_ARGS__);
#endif

#endif
