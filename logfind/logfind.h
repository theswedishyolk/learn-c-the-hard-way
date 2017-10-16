# ifndef __logfind_h
# define __logfind_h

#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"

#define MAX_NAMELENGTH 20
#define MAX_FILES 20

char **get_filenames(char *filename);

#endif
