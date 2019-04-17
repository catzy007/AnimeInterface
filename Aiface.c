#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define boolean unsigned int
#define true 1
#define false 0

//thanks to https://stackoverflow.com/questions/4761764/how-to-remove-first-three-characters-from-string-with-c
void chopN(char *str, size_t n){
	assert(n!=0 && str!=0);
	size_t len=strlen(str);
	if(n>len){
		return;  // Or: n = len;
	}
	memmove(str, str+n, len-n+1);
}

void msgFetcher(char *command){
	FILE *check;
	char message[255], commd[255];
	int i=0;

	check=popen(command,"r");
	if(fgets(message, sizeof(message), check)==NULL){
		printf("ERROR!");
	}
	pclose(check);
	//printf("%s",message); //debug_line_can_be_removed

	if(message[0]=='A' && message[1]=='I' && message[2]==':'){
		chopN(message, 3);
		strcpy(commd,"./moduleAiface -m \"");
		strcat(commd,message);
		strcat(commd,"\" & sleep 2 && ./moduleMp3 mp3/message.mp3");
		system(commd);
	}

}

void main(){
	while(1){
		msgFetcher("./moduleBatmax");
		msgFetcher("./moduleTele");
		sleep(2);
	}
}
