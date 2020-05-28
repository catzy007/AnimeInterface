#include <json.h>
#include <stdio.h>
#include <time.h> 
#include <string.h>

int timeFormatToMin(const char *jsonObjectTime);

int main(int argc, char **argv) {
	FILE *fp;
	char buffer[2048];
	char buff[100];
	struct json_object *parsed_json;
	struct json_object *status;
	struct json_object *data;
	struct json_object *timings;
	struct json_object *Fajr;
	struct json_object *Dhuhr;
	struct json_object *Asr;
	struct json_object *Maghrib;
	struct json_object *Isha;
	
	system("curl \"http://api.aladhan.com/v1/timingsByCity?city=semarang&country=ID&method=8\" > timing.json");

	fp = fopen("timing.json","r");
	fread(buffer, 2048, 1, fp);
	fclose(fp);

	parsed_json = json_tokener_parse(buffer);

	json_object_object_get_ex(parsed_json, "status", &status);
	printf("Status: %s\n", json_object_get_string(status));

	if(!strcmp("OK",json_object_get_string(status))){
		json_object_object_get_ex(parsed_json, "data", &data);
		json_object_object_get_ex(data, "timings", &timings);
		json_object_object_get_ex(timings, "Fajr", &Fajr);
		json_object_object_get_ex(timings, "Dhuhr", &Dhuhr);
		json_object_object_get_ex(timings, "Asr", &Asr);
		json_object_object_get_ex(timings, "Maghrib", &Maghrib);
		json_object_object_get_ex(timings, "Isha", &Isha);

		printf("Fajr: %s - %d\n", json_object_get_string(Fajr), timeFormatToMin(json_object_get_string(Fajr)));
		printf("Dhuhr: %s - %d\n", json_object_get_string(Dhuhr), timeFormatToMin(json_object_get_string(Dhuhr)));
		printf("Asr: %s - %d\n", json_object_get_string(Asr), timeFormatToMin(json_object_get_string(Asr)));
		printf("Maghrib: - %s %d\n", json_object_get_string(Maghrib), timeFormatToMin(json_object_get_string(Maghrib)));
		printf("Isha: %s - %d\n", json_object_get_string(Isha), timeFormatToMin(json_object_get_string(Isha)));

		time_t now = time (0);
		strftime (buff, 100, "%H:%M", localtime (&now));
		printf("Now: %s - %d\n", buff, timeFormatToMin(buff));
	}
    
	return 0;
}

int timeFormatToMin(const char *formattedTime){
	char tHour[3];
	char tMinu[3];
	tHour[0]=formattedTime[0]; tHour[1]=formattedTime[1];
	tHour[2]='\0';
	tMinu[0]=formattedTime[3]; tMinu[1]=formattedTime[4];
	tMinu[2]='\0';
	return (atoi(tHour)*60) + atoi(tMinu);
}