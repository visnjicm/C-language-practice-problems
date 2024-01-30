#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void MinMaxArray(int* array, int* ptr_min, int* ptr_max, int size);

int main()
{
	//Enter code here
	int array[] = {4,23,5,831,45};
	int min, max;
	int* ptr_min = &min;
	int* ptr_max = &max;
	MinMaxArray(array, ptr_min, ptr_max, 5);

	printf("%p\n", array);
	printf("the min value is %d and the max value is %d \n", min, max);  	


	return 0;
}

void MinMaxArray(int* array, int* ptr_min, int* ptr_max, int size)
{
	int min = array[0]; int max = array[size-1];

	for (int i = 1; i<size-1; i++)
	{
		if (array[i]<min) min = array[i];
		if (array[i]>max) max = array[i];
	}

	*ptr_min = min;
	*ptr_max = max;
}
