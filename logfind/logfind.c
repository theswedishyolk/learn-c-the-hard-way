#include "logfind.h"

int get_filenames(char *path, char filenames[MAX_FILES][MAX_NAMELENGTH]) {
	// Check how many files there are
	FILE *handler = fopen(path, "r");

	check(handler, "Could not find .logfind. Creating it ...");

	char *buf=malloc(MAX_NAMELENGTH*sizeof(char));

	check_mem(buf);

	int number_of_files = 0;

	// Check how many strings that are stored in .logfind

	while(!feof(handler))
	{
		fscanf(handler, "%s", buf);
		++number_of_files;
		if(number_of_files > MAX_FILES){
			log_warn("More than %d files found in .logfind. Ignoring additional entries", MAX_FILES);
			break;
		}
	}

	// EOF is not a filename
	number_of_files -= 1;

	// Rewind to the start
	rewind(handler);

	// Read file names
	int i = 0;
	for(i = 0; i < number_of_files; ++i) {
		fscanf(handler, "%s", buf);
		strcpy(filenames[i], buf);
	}


	fclose(handler);

	return number_of_files;

	// If .logfind doesn't exists, create it
	error:
		free(buf);
		fclose(handler);
		system("touch ~/.logfind");
		exit(-1);

}
