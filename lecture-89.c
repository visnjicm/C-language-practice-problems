#include <stdlib.h>
#include <stdio.h>
#define SIZE 11

int main()
{
	int counter = 1;
	int old_array[] = {1,3,3,5,6,7,7,7,8,12,12};
	int * new_array = (int*) malloc(sizeof(int)*counter);
	if(old_array[0]>0)
	{
	new_array[0] = old_array[0];
	}
	else
	{
	return 0;
	}

	for (int i = 1; i<SIZE; i++)
	{
		if (old_array[i] != old_array[i-1])
		{
		counter++;
		new_array = (int*) realloc(new_array, sizeof(int)*counter);
		new_array[counter-1] = old_array[i];
		}
	}

	for(int i = 0; i<counter; i++)
	{
		printf("%d ", new_array[i]);
	}

	free(new_array);

	return 0;
	
}
