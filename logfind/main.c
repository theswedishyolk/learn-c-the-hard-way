#include "logfind.h"
#include "dbg.h"

int main(int argc, char * argv[])
{
	if(argc<2) {
		printf("USAGE: ./logfind -word ...\n");
		return 0;
	}

	// Declarations
	char *home;
	char filenames[MAX_FILES][MAX_NAMELENGTH];
	char *searchwords_s=malloc(255*sizeof(char));
	char *searchwords_a[argc];
	int number_of_files;
	int boolean_or = 0;
	int flag_index = 0;
	int word_i;
	int i = 0;
	int j = 0;
	int found = 1;

	// Check if -o option is present
	for (i = 0; i < argc; ++i) {
		if (strcmp(argv[i], "-o")==0) {
			log_info("-o is present, praise the lord");
			boolean_or = 1;
			flag_index = i;
		}
	}
	// If -o is present, it needs to be omitted from the
	// array/string of words
	if (boolean_or) {
		for (i = 1; i < argc; ++i) {
			if (i >= flag_index) {
				word_i = i - 1;
			}
			else {
				word_i = i;
			}
			if (strcmp(argv[i], "-o")) {
				searchwords_s = strcat(searchwords_s, argv[i]);
				searchwords_s = strcat(searchwords_s, " ");
				searchwords_a[word_i] = argv[i];
			}
		}
	}

	else {
		i = 0;
		memcpy(searchwords_a, argv, argc*sizeof(char *));
		for (i = 1; i < argc; ++i) {
			searchwords_s = strcat(searchwords_s, argv[i]);
			searchwords_s = strcat(searchwords_s, " ");
		}
	}


	// Read $HOME environment variable
	home = getenv("HOME");
	check(home, "$HOME environment variable variable not set.")

	// Obtain list of files to check
	number_of_files = get_filenames(strcat(home,"/.logfind"), filenames);

	// Check if string is in files

	i = 0;
	j = 1;

	printf("These files have %s \n", searchwords_s);

	for(i = 0; i < number_of_files; ++i) {
		found = 1;
		for (j = 1; j < (boolean_or ? (argc - 1) : argc); ++j) {
			if(!has_string(filenames[i], searchwords_a[j])) {
				found = 0;
			}
		}
		if (found) {
			printf("%s", filenames[i]);
		}
	}

	printf("\n");

	return 1;
error:
	return 0;
}
