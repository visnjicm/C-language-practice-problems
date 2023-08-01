#include <stdio.h>
#include <stdlib.h>
#define SIZE 7

int TwoValsAddToSum(int* arr, int size, int sum, int* val1_index, int* val2_index)
{
	*val1_index = 0;
	*val2_index = size-1;

	while((*val2_index - *val1_index) > 0)
	{
		if ((arr[*val1_index] + arr[*val2_index]) == sum)
		{
			return 1;
		}

		if ((arr[*val2_index] > sum) || (arr[*val1_index] + arr[*val2_index] > sum))
		{
			*val2_index = *val2_index - 1;	
		}
		else
		{
			*val1_index = *val1_index + 1;
		}
	}
	*val1_index = 0;
	*val2_index = 0;
	return 0;
}

int main()
{
	int sum = 16;
	int val1_index;
	int val2_index;
	int arr[] = {1,3,4,7,9,10,12};
	TwoValsAddToSum(arr, SIZE, sum, &val1_index, &val2_index);
	printf("index of val1 %d and index of val2 %d\n", val1_index, val2_index);
	return 0;
}
