#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>

#define boolean unsigned int
#define true 1
#define false 0

//thanks to https://stackoverflow.com/questions/4761764/how-to-remove-first-three-characters-from-string-with-c
//remove first few character from string ===============================
void chopN(char *str, size_t n){
	assert(n!=0 && str!=0);
	size_t len=strlen(str);
	if(n>len){
		return;  // Or: n = len;
	}
	memmove(str, str+n, len-n+1);
}

//fetch message and parse to moduleAiface ==============================
void msgFetcher(char *command){
	FILE *check;
	char message[255], commd[255];
	int i=0, aiStatus;

//do system command to incoming 'command' ------------------------------
	respool: //if fgets fail <-
	do{
		check=popen(command,"r");
		sleep(1);
	}while(check == NULL);

//get and parse the input string ---------------------------------------
	if(fgets(message, sizeof(message), check) == NULL){
		goto respool; //if fgets fail <-
	}
	pclose(check);
	//printf("%s",message); //debug_line_can_be_removed

//call aiface if message valid -----------------------------------------
	if(message[0]=='A' && message[1]=='I' && message[2]==':'){
		chopN(message, 3);
		strcpy(commd,"./moduleAiface -m \"");
		strcat(commd,message);
		strcat(commd,"\" & sleep 2 && ./moduleMp3 mp3/message.mp3");
		do{
			aiStatus=system(commd);
			sleep(1);
		}while(aiStatus != 0);
	}

}

void main(){
	while(1){
		msgFetcher("./moduleBatmax");
		msgFetcher("./moduleTele");
		sleep(2);
	}
}
