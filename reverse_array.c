#include <stdio.h>
#include <stdlib.h>
#define SIZE 5


int reverseArray(char* array, int size);

int main()
{
	char array[SIZE] = "hello";
	reverseArray(array, SIZE);
	printf("%s\n", array);
	return 0;
}

int reverseArray(char* array, int size)
{
	if (size == 0 || size == 1)
	{
		return 1;
	}
	else
	{
		char temp = array[size-1];
		array[size-1] = array[0];
		array[0] = temp;

		return reverseArray(array+1, size-2);
	}
}

