#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "debug.h"
#include "io_handler.h"

#define CTRL_(key) (key & 0x1F)



// OUTPUT

void refreshSCREEN(void){
	// Usage of CSI (Control Sequence Introducer) commands
	// Check out : https://en.wikipedia.org/wiki/ANSI_escape_code#Control_Sequence_Introducer_commands
	
	// "CSI 2 J" ED clear entire screen (and moves cursor to upper left on DOS ANSI.SYS)
	write(STDOUT_FILENO, "\033[2J", 4);
	
	// "CSI n ; m H" CUP moves cursor to row n, column m; default is 1, 1
	write(STDOUT_FILENO, "\033[H", 3);
}


// INPUT

char getKEY(void){
	char c;
	
	if(read(STDIN_FILENO, &c, 1) == -1) erred();
	
	return c;
}

void processKEY_PRESS(void){
	char c = getKEY();
	if(c == CTRL_('q')) exit(0);
	if(iscntrl(c)) printf("%d\r\n",c);
	else printf("%d ('%c')\r\n",c, c);
}

