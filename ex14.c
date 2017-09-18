#include <stdio.h>
#include <ctype.h>
#include <string.h>

// forward declarations

void print_letters(char arg[], int argc);

void print_arguments(int argc, char *argv[]) 
{
	int i = 0;
	char *string;

	for(i = 0; i < argc; i++)
	{
		string=argv[i];
		print_letters(string,strlen(string));
	}
}

void print_letters(char arg[], int argc)
{
	int i = 0;

	for(i = 0; i < argc; i++)
	{
		char ch = arg[i];

		if(isdigit(ch))
		{
			printf("'%c' == %d ", ch, ch);
		}
	}
	printf("\n");
}


int main(int argc, char *argv[])
{
	print_arguments(argc, argv);

	return 0;
}
