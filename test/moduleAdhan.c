#include <json.h>
#include <stdio.h>
#include <time.h> 

int main(int argc, char **argv) {
	FILE *fp;
	char buffer[2048];
	struct json_object *parsed_json;
	struct json_object *status;
	struct json_object *data;
	struct json_object *timings;
	struct json_object *Fajr;
	struct json_object *Dhuhr;
	struct json_object *Asr;
	struct json_object *Maghrib;
	struct json_object *Isha;

	fp = fopen("timing.json","r");
	fread(buffer, 2048, 1, fp);
	fclose(fp);

	parsed_json = json_tokener_parse(buffer);

	json_object_object_get_ex(parsed_json, "status", &status);
	json_object_object_get_ex(parsed_json, "data", &data);
	json_object_object_get_ex(data, "timings", &timings);
	json_object_object_get_ex(timings, "Fajr", &Fajr);
	json_object_object_get_ex(timings, "Dhuhr", &Dhuhr);
	json_object_object_get_ex(timings, "Asr", &Asr);
	json_object_object_get_ex(timings, "Maghrib", &Maghrib);
	json_object_object_get_ex(timings, "Isha", &Isha);

	printf("Status: %s\n", json_object_get_string(status));
	printf("Fajr: %s\n", json_object_get_string(Fajr));
	printf("Dhuhr: %s\n", json_object_get_string(Dhuhr));
	printf("Asr: %s\n", json_object_get_string(Asr));
	printf("Maghrib: %s\n", json_object_get_string(Maghrib));
	printf("Isha: %s\n", json_object_get_string(Isha));

	char buff[100];
    time_t now = time (0);
    strftime (buff, 100, "%H:%M", localtime (&now));
    printf ("Now: %s\n", buff);

	return 0;
}