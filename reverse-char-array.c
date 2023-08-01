#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseArray(char* array);

int main()
{
	char array[SIZE] = "Hello";
	char reverseArray[SIZE-1];
}

char reverseArray(char* array)
{
	if (array[0] == '\0') ;

	return strcat(reverseArray(array+1), array[0]);
}
