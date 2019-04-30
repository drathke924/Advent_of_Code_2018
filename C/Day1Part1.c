#include <stdio.h>

int main()
{
	int sum = 0;
	FILE* finput;
	int n;
	finput = fopen("Day1.txt", "r");
	while (fscanf(finput, "%d\n", &n) != EOF) {
		sum += n;
	}
	fclose(finput);
	printf("Final result: %d", sum);

	return 0;
}
