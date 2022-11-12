#ifndef DBG_H
#define DBG_H

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>

void tprintf(const char *fmt, ...) {
	time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

	

    fprintf (stderr, "[%d/%d/%d %d:%d:%d] ", timeinfo->tm_year + 1900,timeinfo->tm_mon + 1, timeinfo->tm_mday,  timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
}

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
