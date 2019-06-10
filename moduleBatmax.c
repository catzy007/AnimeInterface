#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define boolean unsigned int
#define true 1
#define false 0

//https://cryptii.com/pipes/text-octal

//you might want to edit this ==========================================
#define MyMax 95 //change this to set maximum battery percentage. default = 90
#define MyMin 60 //change this to set minimum battery percentage. default = 40
#define MyOff 45 //change this to set shutdown battery percentage. default = 20

//batmax function ======================================================
int getBattPerc(void); //this function will return current battery percentage
boolean getStatusCharge(void); //this fucntion will return true if battery is charged

//main function ========================================================
void main(){
	int status = 0;
	
//if laptop is discharged and battery under MyOff ----------------------
	if(getStatusCharge() == false && getBattPerc() <= MyOff){
		do{
			sleep(1);
			status = system("xterm -e poweroff");
		}while(status != 0);
//if laptop is discharged and battery less than MyMin ------------------
	}else if(getStatusCharge() == false && getBattPerc() <= MyMin){
		printf("AI:Plug|Charger|Now!\n");
//if laptop is discharged and battery at safe level --------------------
	}else if(getStatusCharge() == false){
		printf("discharging. Curr:%d%% Max:%d%% Min:%d%% Off:%d%%\n",
			getBattPerc(),MyMax,MyMin,MyOff);
//if laptop is charged and battery more than MyMax ---------------------
	}else if(getStatusCharge() == true && getBattPerc() >= MyMax){
		printf("AI:Unplug|Charger|Now!\n");
//if laptop is charged and battery at safe level -----------------------
	}else{
		printf("Charging. Cur:%d%% Max:%d%% Min:%d%% Off:%d%%\n",
			getBattPerc(), MyMax, MyMin, MyOff);
	}
}

//this function will return current battery percentage =================
int getBattPerc(void){
//some variables -------------------------------------------------------
	FILE *sysCall;
	char strTemp[6], *strPerc;
	int i, intPerc=0;
	int strPercLen=(sizeof(char)*sizeof(strTemp))-1;

//do system command to check battery percentage ------------------------
	respool: //if fgets fail <-
	do{
		//sysCall = popen("acpi -b | awk '{print $4}'", "r");
		sysCall = popen("\141\143\160\151\40\55\142\40\174\40\141\167\153\40\47\173\160\162\151\156\164\40\44\64\175\47", "r");
		sleep(1);
	}while(sysCall == NULL);

//get and parse the input string ---------------------------------------
	if((strPerc = fgets(strTemp, strPercLen, sysCall)) == NULL){
		goto respool; //if fgets fail <-
	}
	pclose(sysCall);
	
//filter the input string ----------------------------------------------
	for(i=0; i<strPercLen; i++){
		if(strPerc[i]=='\045' || strPerc[i]=='\54'){
			strPerc[i]='\040';
		}
	}
	//printf("%s",strperc); //debug_line_can_be_removed
	
//convert input string to integer and return ---------------------------
	intPerc=atoi(strPerc);
	return intPerc;
}

//this fucntion will return true if battery is charged =================
boolean getStatusCharge(void){
//some variables -------------------------------------------------------
	FILE *sysCall;
	int i, mark=0;
	char strTemp[16], *strState;
	char disState[]="Charging,";
	int strStateLen=(sizeof(char)*sizeof(strTemp))-1;
	int strDisLen=(sizeof(char)*sizeof(disState))-1;

//do system command to check battery status ----------------------------
	respool: //if fgets fail <-
	do{
		//sysCall = popen("acpi -b | awk '{print $3}'", "r");
		sysCall = popen("\141\143\160\151\40\55\142\40\174\40\141\167\153\40\47\173\160\162\151\156\164\40\44\63\175\47", "r");
		sleep(1);
	}while(sysCall == NULL);

//get and parse the input string ---------------------------------------
	if((strState = fgets(strTemp, strStateLen, sysCall)) == NULL){
		goto respool; //if fgets fail <-
	}
	pclose(sysCall);

//comparator algoritm --------------------------------------------------
	mark=0;
	for(i=0; i<strDisLen; i++){
		if(strState[i] == disState[i]){
			mark+=1;
		}
	}
	//printf("%s %s %d %d\n",strstate,state,mark,sizeof(state)-1); //debug_line_can_be_removed
	if(mark == strDisLen){
		return true;
	}
	return false;
}
