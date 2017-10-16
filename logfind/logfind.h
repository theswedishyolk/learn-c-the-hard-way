# ifndef __logfind_h
# define __logfind_h

#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"

#define MAX_NAMELENGTH 255
#define MAX_FILES 20


int get_filenames(char *path, char filenames[MAX_FILES][MAX_NAMELENGTH]);
char *home;
char filenames[MAX_FILES][MAX_NAMELENGTH];
int number_of_files;


#endif
