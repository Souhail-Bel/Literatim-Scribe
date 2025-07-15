#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "editor.h"

int main() {
	enter_RAW_MODE();
	
	// Input character
	char c;

	while( read(STDIN_FILENO, &c, 1) && (c != 'q'))
		// Check that it's printable
		if(iscntrl(c)) printf("%d\r\n",c);
		else printf("%d ('%c')\r\n",c, c);
	
	
	exit_RAW_MODE();
	return 0;
}
