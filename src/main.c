#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "editor.h"
#include "io_handler.h"

int main() {
	RAW_MODE();
	
	while(1){
		refreshSCREEN();
		processKEY_PRESS();
	}
	
	
	// If exiting RAW mode is done through this way, it will break the terminal
	// exit_RAW_MODE();
	return 0;
}
