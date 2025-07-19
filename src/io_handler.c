#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "debug.h"
#include "io_handler.h"

#define CTRL_(key) (key & 0x1F)

char getKEY(void){
	char c;
	
	read(STDIN_FILENO, &c, 1);
	
	return c;
}

void processKEY_PRESS(void){
	char c = getKEY();
	if(c == CTRL_('q')) exit(0);
	if(iscntrl(c)) printf("%d\r\n",c);
	else printf("%d ('%c')\r\n",c, c);
}