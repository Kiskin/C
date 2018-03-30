/*
COMP 348 Assignment One
Kisife GILES 
ID: 40001926
*/

#include <dirent.h> //directory functions
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h> //sorting functions
#include <stdio.h>
#include "text.h"
#include "traversal.h"

int main( int argc, char *argv[] ) {

	if(argc <2 || argc >3){

		printf("Incorrect number of command line arguments. Please, include a string to search!");

	}
	
	readDirectories(argv[1]);

	
return 0;
}
