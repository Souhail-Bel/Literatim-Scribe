#include <termios.h>
#include <unistd.h>
#include "raw_mode.h"

struct termios orig_termios;

void enter_RAW_MODE(void){
	tcgetattr(STDIN_FILENO, &orig_termios);
	
	// Make copy from global
	struct termios raw = orig_termios;
	
	raw.c_lflag &= ~(ECHO);
	
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}


void exit_RAW_MODE(void){
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}