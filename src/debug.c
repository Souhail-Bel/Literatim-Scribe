#include <debug.h>
#include <stdarg.h>


void errMsg(const char* format, ...){
	va_list args;
	va_start(args, format);
	printf("\033[30;101m ►\033[3mWARNING:\033[0m ");
	vprintf(format, args);
	putchar('\n');
	va_end(args);
}
