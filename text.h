#ifndef text_h_
#define text_h_

	extern void writeToFile(char *filepath, char *data);
	extern  char*  searchFile(char *filename, char *srchStr);
	extern void searchForString(char *stringToSearch, char *srchStr, char * fileName);
	extern int writeReport( char *data,int counter);
#endif