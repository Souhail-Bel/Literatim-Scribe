#include <termios.h>
#include <unistd.h>
#include <stdlib.h>

#include "debug.h"
#include "editor.h"

// Current terminal
static struct termios orig_termios;


void disable_RAW_MODE(void){
	if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios) == -1) erred();
}

void RAW_MODE(void){
	if(tcgetattr(STDIN_FILENO, &orig_termios) == -1) erred();
	
	atexit(disable_RAW_MODE);
	
	// Make copy from global
	struct termios raw = orig_termios;
	
	
	/*
	https://pubs.opengroup.org/onlinepubs/7908799/xsh/termios.h.html
		Termios structure
			tcflag_t
				c_iflag: Input modes
				c_oflag: Output modes
				c_cflag: Control modes
				c_lflag: Local Modes
	
		Input modes:
			Disable
				Start/stop output control
				Map CR to NL on input
		Output modes:
			Disable
				Post-process output
		Local modes:
			Disable	
				Echoing
				Canonical/cooked mode
				Signals
				Extended input character processing
	*/
	raw.c_iflag &= ~(IXON | ICRNL);
	raw.c_oflag &= ~(OPOST);
	raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
	
	
	// TCSAFLUSH : change occurs when all output written to STDIN_FILENO and discards queued input
	if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) erred();
}

