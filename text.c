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
#include "report.h"


//open the file and read all of the file into one string

char*  searchFile(char *filename, char *srchStr){
		
		static char fileContents[10000];
		int i=0;
		int c;

		FILE *fp = fopen(filename, "r");

		if (fp) {
		    while ((c = getc(fp)) != EOF){

		        fileContents[i++]=c;
		}
		fileContents[i]='\0';
		 fclose(fp);
		}
		else{
			perror("File can not be opened!");
		}

	return fileContents;

}
//Method searches file and count the number of occurances of a passed string.
void searchForString( char* stringToSearch, char *srchStr, char* fileName) {
	
	int n = 0;
	int m = 0;
	int counter =0;
	// contains the length of search string
	int len = strlen(srchStr); 

	while (stringToSearch[n] != '\0') {

	// if first character of search string matches
		if (toupper(stringToSearch[n]) == toupper(srchStr[m])) { 

			// keep on searching

			while (toupper(stringToSearch[n]) == toupper(srchStr[m])
					&& stringToSearch[n] != '\0') {
				n++;
				m++;
			}

			// if the sequence of characters matching with the length of searched string
			if (m == len ) {

				// BINGO!! There is a match!
				counter++;
				for (int i = 0; i < len; i++) {

					stringToSearch[n - len + i] = toupper(srchStr[i]);

				}
				printf(" Match found ! \n");
			}
		} else {
				 // if first character of search string does not match

			while (stringToSearch[n] != ' ') { // Skip to next word
				n++;
				if (stringToSearch[n] == '\0')
					break;
			}
		}
		
		n++;
		m = 0; // reset the counter to start from first character of the search string.
		
	}

	//print report to file
	writeToFile(fileName, stringToSearch);


	//Record file path and the number of updates for subsiquent writing to report file.
	 fileEntry(counter, fileName);


	//Reset the counter.
	counter = 0;
}

//write modified string back to file
void writeToFile(char *filepath, char *data) {

	FILE *fp = fopen(filepath, "w");
	if (fp != NULL) {
		fputs(data, fp);
		fclose(fp);
	}
}
