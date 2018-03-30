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
#include <stdlib.h> 
#include <stdio.h>
#include "report.h"


//Define global variables and struct to use for output.
	int i=0;
	struct report_struct {
			int nrOfUpdates;
			char fileName[100];
			};
	//struct myStruct report_struct;
	struct report_struct *report[100];

//Method constructs a struct out of each line of the output( number of updates and file path/name).
void fileEntry(int count, char * str){

	struct report_struct* myEntry =  (struct report_struct*)malloc(sizeof(struct report_struct));
	myEntry->nrOfUpdates=count;
	strcpy(myEntry->fileName,str) ;
	report[i++]=myEntry;
}


// qsort struct comparision function using the update count.

int struct_cmp_by_update(const void *a, const void *b) { 

    		struct report_struct *ia = (struct report_struct *)a;
    		struct report_struct *ib = (struct report_struct *)b;

    	return  (int)((ia->nrOfUpdates - ib->nrOfUpdates));
 
} 


//Quick-sort (by number of updates) array of structs and write the contents to file. 

void sortAndSaveReport(){

 size_t structs_len = sizeof(report) / sizeof(struct  report_struct);
    qsort(report, structs_len, sizeof(struct  report_struct), struct_cmp_by_update);

	printf("Seacrh begins in the current directory");




	for(int i=structs_len-1; i>-1; i--){
		//Write results to report file
		writeReport(report[i]->fileName,report[i]->nrOfUpdates);
		
	}
	//Free memory used in the structs.
	for(int j=0; j<structs_len; j++){

		free(report[j]);

		}


}
 



//Method writes repport to text file "CountReport.txt".

int writeReport(char str[],int counter) {

	char report[100];
	char cwd[1024];

	getcwd(cwd, sizeof(cwd));

	strcpy(report, " ");

	sprintf(report, "%d",counter);
	strcat(report, "\t \t \t \t \t \t");
	strcat(report, cwd);
	strcat(report, "/");
	strcat(report, str);

	FILE *fp = fopen("CountReport.txt", "a");
	if (fp != NULL) {
		fputs(report, fp);
		fputs("\n", fp);
		fclose(fp);
	}
	return 0;
}
