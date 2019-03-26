#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char command[50];
	if(argv[1]!=NULL){
		strcpy(command, "mplayer ");
		strcat(command, argv[1]);
		if(system(command)!=0){
			printf("ERROR!");
			exit(0);
		}
	}
	return 0;
}
