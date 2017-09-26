#ifndef __dbg_h__
#define __dbg_h__

#include <stdio.h>
#include <errno.h>
#include <string.h>

#ifdef NDEBUG
#define debug(M, ...)
#else
#define debug(m, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n",\
	__FILE__, __LINE__, ##__VA_ARGS__)
#endif

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define log_err(M, ...) fprintf(stderr,\
	"[ERROR] (%s%d: errno: %s) " M "\n", __FILE__, __LINE__,\
	clear_errno(), ##__VA_ARGS__)


#define log_warn(M, ...) fprintf(stderr,\
	"[WARN] (%s:%d: errno:%s" M "\n",\
	__FILE__, __LINE__, clear_erno##__VA_ARGS__)

#define check(A,M, ...) if(!(A)) {\
	log_err(M,##__VA_ARGS__); errno=0; goto error; }
