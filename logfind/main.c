#include "logfind.h"
#include "dbg.h"

int main(int argc, char * argv[])
{
	//check(argc>1, "USAGE: ./logfind -word ...");

	// Read $HOME environment variable
	home = getenv("HOME");
	check(home, "$HOME environment variable variable not set.")

	// Obtain list of files to check
	char filenames[MAX_FILES][MAX_NAMELENGTH];
	number_of_files = get_filenames(strcat(home,"/.logfind"), filenames);

	// Print list of files to check
	for(int i = 0; i< number_of_files; i++) {
		log_info("FILE: %s", filenames[i]);
	}

	return 0;
error:
	return 0;
}
