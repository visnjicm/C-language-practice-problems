#include <stdio.h>
#include <stdlib.h>
#define SIZE 9

int ArraySecondSmallest(int* arr, int size)
{
	int smallest;
	int second_smallest;
	int temp;

	if (size == 1)
	{
		smallest = arr[0];
		second_smallest = arr[0];
		return second_smallest;
	}
	else
	{
		smallest = arr[0];
		second_smallest = arr[1];
	}

	if (second_smallest < smallest)
	{
		temp = smallest;
		smallest = second_smallest;
		second_smallest = temp;
	}

	for (int i = 2; i<size; i++)
	{
		if (arr[i] < smallest)
		{
			temp = smallest;
			smallest = arr[i];
			second_smallest = temp;
		}

		if (arr[i] > smallest && arr[i] < second_smallest)
		{
			second_smallest = arr[i];
		}
	}


	return second_smallest;
}


int main()
{
	int arr[] = {1,2,5,3,6,3,1,2,5};
	printf("The second smallest value in the array is %d\n", ArraySecondSmallest(arr, SIZE));
	return 0;
}
