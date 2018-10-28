#include "mybatmax.h"

//https://cryptii.com/pipes/text-octal

//if battery percentage more than equ max
int MyBatPrecMax(int max){
	FILE *fp1;
	char strperc[6];
	int i,intperc=0;
	///fp1 = popen("upower -i $(upower -e | grep 'BAT') | grep percentage | awk '/perc/{print $2}'", "r");
	///fp1 = popen("\165\160\157\167\145\162\40\55\151\40\44\50\165\160\157\167\145\162\40\55\145\40\174\40\147\162\145\160\40\47\102\101\124\47\51\40\174\40\147\162\145\160\40\160\145\162\143\145\156\164\141\147\145\40\174\40\141\167\153\40\47\57\160\145\162\143\57\173\160\162\151\156\164\40\44\62\175\47", "r");
	//fp1 = popen("acpi -b | awk '{print $4}'", "r");
	fp1 = popen("\141\143\160\151\40\55\142\40\174\40\141\167\153\40\47\173\160\162\151\156\164\40\44\64\175\47", "r");
	//if command failed to run
	if(fp1==NULL){
		return -1;
	}
	fgets(strperc,sizeof(strperc)-1,fp1);
	pclose(fp1);
	for(i=0;i<sizeof(strperc);i++){
		if(strperc[i]=='\045' || strperc[i]=='\54'){
			strperc[i]='\040';
		}
	}
	//printf("%s",strperc); //debug_line_can_be_removed
	intperc=atoi(strperc);
	if(intperc>=max){
		return 1;
	}
	return 0;
}

//if battery percentage less than equ min
int MyBatPrecMin(int min){
	FILE *fp1;
	char strperc[6];
	int i,intperc=0;
	///fp1 = popen("upower -i $(upower -e | grep 'BAT') | grep percentage | awk '/perc/{print $2}'", "r");
	///fp1 = popen("\165\160\157\167\145\162\40\55\151\40\44\50\165\160\157\167\145\162\40\55\145\40\174\40\147\162\145\160\40\47\102\101\124\47\51\40\174\40\147\162\145\160\40\160\145\162\143\145\156\164\141\147\145\40\174\40\141\167\153\40\47\57\160\145\162\143\57\173\160\162\151\156\164\40\44\62\175\47", "r");
	//fp1 = popen("acpi -b | awk '{print $4}'", "r");
	fp1 = popen("\141\143\160\151\40\55\142\40\174\40\141\167\153\40\47\173\160\162\151\156\164\40\44\64\175\47", "r");
	//if command failed to run
	if(fp1==NULL){
		return -1;
	}
	fgets(strperc,sizeof(strperc)-1,fp1);
	pclose(fp1);
	for(i=0;i<sizeof(strperc);i++){
		if(strperc[i]=='\045' || strperc[i]=='\54'){
			strperc[i]='\040';
		}
	}
	intperc=atoi(strperc);
	if(intperc<=min){
		return 1;
	}
	return 0;
}

//if battery state charging or discharging
int MyBatState(){
	FILE *fp2;
	int i,mark=0;
	char strstate[16];
	char state[]="Discharging,";
	///fp2 = popen("upower -i $(upower -e | grep 'BAT') | grep state | awk '/state/{print $2}'", "r");
	///fp2 = popen("\165\160\157\167\145\162\40\55\151\40\44\50\165\160\157\167\145\162\40\55\145\40\174\40\147\162\145\160\40\47\102\101\124\47\51\40\174\40\147\162\145\160\40\163\164\141\164\145\40\174\40\141\167\153\40\47\57\163\164\141\164\145\57\173\160\162\151\156\164\40\44\62\175\47", "r");
	//fp2 = popen("acpi -b | awk '{print $3}'", "r");
	fp2 = popen("\141\143\160\151\40\55\142\40\174\40\141\167\153\40\47\173\160\162\151\156\164\40\44\63\175\47", "r");
	//if command failed to run
	if(fp2==NULL){
		return -1;
	}
	fgets(strstate,sizeof(strstate)-1,fp2);
	pclose(fp2);
	mark=0;
	for(i=0;i<sizeof(state);i++){
		if(strstate[i]==state[i]){
			mark+=1;
		}
	}
	//printf("%s %s %d %d\n",strstate,state,mark,sizeof(state)-1);
	if(mark==sizeof(state)-1){
		return 0;
	}
	return 1;
}