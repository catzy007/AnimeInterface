#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main(){
	int status=0;
	do{
		status=system("pkill Aiface");
		printf("Terminating old process %d\n",status);
		sleep(1);
	}while(status != 256);
	if(system("./Aiface &") == 1){
		printf("Launched!\n");
	}
}
