#include <json.h>
#include <stdio.h>

int main(int argc, char **argv) {
	FILE *fp;
	char buffer[2048];
	struct json_object *parsed_json;
	struct json_object *status;
	struct json_object *data;
	struct json_object *timings;
	struct json_object *time;

	size_t i;	

	fp = fopen("timing.json","r");
	fread(buffer, 2048, 1, fp);
	fclose(fp);


	//printf("%s\n",buffer);

	parsed_json = json_tokener_parse(buffer);

	json_object_object_get_ex(parsed_json, "status", &status);
	json_object_object_get_ex(parsed_json, "data", &data);
	json_object_object_get_ex(data, "timings", &timings);
	json_object_object_get_ex(timings, "Fajr", &time);
	// json_object_object_get_ex(parsed_json, "age", &age);
	// json_object_object_get_ex(parsed_json, "friends", &friends);

	printf("Status: %s\n", json_object_get_string(status));
	printf("Timings: %s\n", json_object_get_string(timings));
	printf("Fajr: %s\n", json_object_get_string(time));
	// printf("Age: %d\n", json_object_get_int(age));

	// n_friends = json_object_array_length(friends);
	// printf("Found %lu friends\n",n_friends);

	// for(i=0;i<n_friends;i++) {
	// 	friend = json_object_array_get_idx(friends, i);
	// 	printf("%lu. %s\n",i+1,json_object_get_string(friend));
	// }	
}