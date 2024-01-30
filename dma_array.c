#include <stdlib.h>
#include <stdio.h>


int main()
{
	int counter = 1;
	int * array = (int*) malloc(sizeof(int)*counter);

	while (1)
	{
	int element;
	printf("Enter next element in array: ");
	scanf("%d", &element);
	if (element>=0)
	{
		array = (int*) realloc(array, sizeof(int)*counter);
		array[counter-1] = element;
	}
	else
	{
		break;
	}
	printf("\n");
	counter++;
	}

	for (int i = 0; i<(counter-1); i++)
	{
		printf("%d ", array[i]);
	}
	free(array);
	
	return 0;
}
