#include <termios.h>
#include <unistd.h>
#include <stdlib.h>

#include "debug.h"

/*

First thought of as taking a string playing the role of the error message
but perror(const char* s) does this job well enough

Given the kind of errors that can be raised...
This should be well enough.

*/

void erred(void){
	write(STDOUT_FILENO, "\033[2J", 4);
	write(STDOUT_FILENO, "\033[H", 3);
	
	perror("\033[30;101m ►\033[3mERROR:\033[0m ");
	exit(-1);
}
