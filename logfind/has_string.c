#include "logfind.h"

int has_string(char *path, char* cmpstring) {
	FILE *handler = fopen(path, "r");

	check(handler,"No file found at %s. Keep calm and carry on...", path);

	char *buf=malloc(MAX_NAMELENGTH*sizeof(char));

	check_mem(buf);

	// Check if file constains specified string

	while(!feof(handler)) {
		fscanf(handler, "%s", buf);
		if(strcmp(buf, cmpstring)==0) {
			return 1;
		}
	}

	return 0;


error:
	fclose(handler);
	return 0;

}
