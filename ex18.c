#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


void die(char *msg)
{
	if(errno) {
		perror(msg);
	}
	else {
		printf("ERROR: %s\n", msg);
	}
	exit(-1);
}

// a typedef creates a fake type
// in this case for a function pointer

typedef int(*compare_cb) (int a, int b);

/* A classic bubble sort which uses
 *compare_cb to do the sorting 
 */

int *bubble_sort(int *numbers, int cnt, compare_cb cmp)
{
	int tmp = 0;
	int j = 0;
	int i = 0;
	int *target = malloc(cnt * sizeof(int));

	if (!target) {
		die("Memory Error.");
	}

	memcpy(target, numbers, cnt * sizeof(int));
	for(i = 0; i < cnt; i++) {
		for(j = 0; j < cnt - 1; j++) {
			if (cmp(target[j], target[j + 1]) > 0) {
				tmp = target[j + 1];
				target[j + 1] = target[j];
				target[j] = tmp;
			}
		}
	}
	return target;
}

int sorted_order(int a, int b)
{
	return a - b;
}

int reverse_order(int a, int b)
{
	return b - a;
}
 
int strange_order(int a, int b) {
	if (a == 0 || b == 0) {
		return 0;
	}
	else {
		return a % b;
	}
}

/**
 * Used to test that we're
 * sorting everything correctly by
 * sorting and printing it out
 */

void test_sorting(int *numbers, int cnt, compare_cb cmp)
{
	int i = 0;
	int *sorted = bubble_sort(numbers, cnt, cmp);

	if(!sorted) {
		die("Failed to sort as requested");
	} 

	for(i = 0; i < cnt; i++) {
		printf("%d ", sorted[i]);
	}
	printf("\n");

	free(sorted);
}




int main(int argc, char *argv[])
{
	if (argc < 2) {
		die("USAGE: ex18 4 1 3 5 6");
	}
	int i = 0;
	int count = argc - 1;
	char **inputs = argv + 1;
	int *numbers = malloc(count * sizeof(int));

	for (i = 0; i < count; i++) {
		numbers[i] = atoi(inputs[i]);
	}

	test_sorting(numbers, count, sorted_order);
	test_sorting(numbers, count, reverse_order);
	test_sorting(numbers, count, strange_order);

	free(numbers);	
	return 0;
}

