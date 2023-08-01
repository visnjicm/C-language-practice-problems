#include <stdio.h>
#include <stdlib.h>
#define SIZE 5


int Ext2(int* arr, int size)
{
	if ((size == 1) || (size == 0))
	{
		return 1;
	}

	if (arr[0] < 0)
	{
		if ((size%2) != 0)
		{
			if (arr[size-1] < 0)
			{
				Ext2(arr+1, size-2);
			}
			else
			{
				return 0;
			}
		}
		else
		{
			if (arr[size-1] > 0)
			{
				Ext2(arr+1, size-2);
			}
			else
			{
				return 0;
			}

		}
	}
	else
	{
		if ((size%2) != 0)
		{
			if (arr[size-1] > 0 )
			{
				Ext2(arr+1, size-2);
			}
			else
			{
				return 0;
			}

		}
		else
		{
			if (arr[size-1] < 0 )
			{
				Ext2(arr+1, size-2);
			}
			else
			{
				return 0;
			}
			
		}
	}	
}

int main()
{
	int arr[] = {-1,2,-4};

	printf("Result is %d\n", Ext2(arr, SIZE));
	
	return 0;
}
