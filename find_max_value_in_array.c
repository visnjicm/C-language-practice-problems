#include <stdio.h>
#include <stdlib.h>
#define SIZE 7

int maxValue(int* grades, int size);

int main()
{
	int grades[SIZE] = {80,85,72,90,95,31,41};
	int maxGrade = maxValue(grades, SIZE);
	printf("max value is %d", maxGrade);
	return 0;
}

int maxValue(int* grades, int size)
{
	if (size == 1)
	{
		return grades[0];
	}
	else
	{
		if (grades[size-1] > grades[0])
		{
			return maxValue(grades+1, size - 1);
		}
		if (grades[size-1] < grades[0])
		{
			return maxValue(grades, size - 1);
		}

	}
}
