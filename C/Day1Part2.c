#include <stdio.h>
#include <stdlib.h>

int main()
{
	int sum = 0, max = 0, min = 0, found = 0, tmp, n;
	int* values;
	FILE* finput;
	finput = fopen("Day1.txt", "r");
	while (fscanf(finput, "%d\n", &n) != EOF) {
		sum += n;
		if (sum > max) {max = sum;}
		if (sum < min) {min = sum;}
	}
	sum = 0;
	rewind(finput);
	values = malloc(sizeof(int) + 1);
	size_t valuesize = 1;
	while (found == 0) {
		if (fscanf(finput, "%d\n", &n) == EOF) {
			rewind(finput);
			fscanf(finput, "%d\n", &n);
		}
		sum += n;
		if ((sum + abs(min)) > valuesize) {
			values = realloc(values, sizeof(int)*((sum + abs(min)) + 1) + 1);
			valuesize = (sum + abs(min)) + 1;
		}
		if (values[sum + abs(min)] && values[sum + abs(min)] == 1) {
			printf("Final Result: %d", sum);
			found = 1;
		}
		else {
			values[sum + abs(min)] = 1;
		}
	}
	fclose(finput);
	free(values);
	return 0;
}
