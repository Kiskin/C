/*
 * correction.c
 *
 *  Created on: 2018-02-05
 *      Author: GILES
 */

#include <stdlib.h> //sorting functions
#include <stdio.h>
#include <dirent.h> //directory functions
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include "traversal.h"
#include "text.h"
#include "report.h"

static struct dirent *sd;
//This file contains directory traversal logic.

//Method reads directories starting from the current directory.

void readDirectories(char * string) {
	DIR *dir;
	dir = opendir(".");

	if (dir == NULL) {

		perror("Directory can not be opened!");
		exit(1);

	} else {
		
		readDirHelper(dir, string);
	}

	closedir(dir);

}

//Helper method for directory traversal
void readDirHelper(DIR * dir, char *str) {

	while ((sd = readdir(dir)) != NULL) {
		
		//If not current or parent directory
		if (((strcmp(sd->d_name, ".")) && (strcmp(sd->d_name, ".."))) != 0) {

			if ((is_dir(sd->d_name) == 0)) {

				if (!(access(sd->d_name, X_OK) == 0)) {

					printf(">> %s\n", sd->d_name);

					//processing here...
					char *fileStringTest = searchFile(sd->d_name, str);

					char fileString[100000];
					strcpy(fileString,fileStringTest);


					searchForString(fileString, str,sd->d_name);

						} 
				else {
							printf("%s : is an executable file. Skipped!!!\n",sd->d_name);
							continue;
		
						}

					} else {

				//What to do if directory
				printf("%s is a directory:  \n", sd->d_name);
				
			}

		} 

	}
//After reading all files, sort and print the report file.
 sortAndSaveReport();

}

//Returns true if directory is a file

int is_file(char* path) {
	struct stat buf;
	stat(path, &buf);
	return S_ISREG(buf.st_mode);
}

//Returns true if a directory is not a file.
int is_dir(char* path) {
	struct stat buf;
	stat(path, &buf);
	return S_ISDIR(buf.st_mode);
}
