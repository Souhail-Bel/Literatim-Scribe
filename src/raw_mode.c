#include <termios.h>
#include <unistd.h>
#include "raw_mode.h"

// Current terminal
static struct termios orig_termios;

void enter_RAW_MODE(void){
	tcgetattr(STDIN_FILENO, &orig_termios);
	
	// Make copy from global
	struct termios raw = orig_termios;
	
	// Disable echoing, canonical/cooked mode and SGINT (CTRL-C) and SIGTSTP (CTRL-Z) interrupts
	raw.c_lflag &= ~(ECHO | ICANON | ISIG);
	
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}


void exit_RAW_MODE(void){
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}