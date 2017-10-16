#include "logfind.h"

char ** get_filenames(char* filename) {
	// Allocate memory
	char **filenames = malloc(2*sizeof(char));
	check_mem(filenames);

	// Read from file
	FILE *handler = fopen(filename, "r");

	check(handler, "File could not be opened.");
	


	
	return filenames;

	error:
		return -1;

}
