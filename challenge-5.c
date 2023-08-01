#include <stdio.h>
#include <stdlib.h>
#define SIZE 5


int checkSort(int* array, int size, int* P);

int main()
{
	int array[] = {1,2,5,3,10};
	int P = 1;
	int R = checkSort(array, SIZE, &P);
	printf("R value is %d and P value is %d\n", R, P);
	return 0;
}

int checkSort(int* array, int size, int* P)
{
	if (array[0] < array[1])
	{
		if (size == 2) return 1;

		return checkSort(array+1, size-1, P);
	}

	if (array[0] > array[1])
	{
		*P = 0;
		return 0;
	}

	if (array[0] == array[1])
	{
		if (size == 2) return 1;

		*P = 0;

		return checkSort(array+1, size-1, P);
	}
}
