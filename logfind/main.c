#include "logfind.h"
#include "dbg.h"

int main(int argc, char * argv[])
{
	check(argc>1, "USAGE: ./logfind -word ...");

	char **test =  get_filenames("lol.txt");

	free(test);
	return 0;
error:
	return -1;
}
