#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>


void * arr_insert(int type, double value, int index, void * array, int* size)
{
	//printf("%d\n", ((int*) array)[0]);
	
	*size = (*size)+1;
	printf("%d\n", (*size));
	
	if (index >= (*size))
	{
		printf("Nope, you cannot do that\n");
	}

	else if (type == sizeof(int))
	{
		int * temp = (int *) array;  
		temp = (int*) realloc(temp, sizeof(int)*(*size));

		printf("hello %d\n", temp[1]);

		for (int j = (*size)-1; j>=index; j-= 1)
		{
			printf("i value %d\n", j);
			printf("index %d\n", index);
			if (j == index)
			{
				temp[j] = (int) value;
			}		
			else
			{
				temp[j] = temp[j-1];
				printf("temp %d\n", temp[j]);
			}
		}
		printf("yes %d\n", temp[3]);
		return temp;
	}
	else if (type == sizeof(double))
	{
		double * temp = (double *) array;
		temp = (double*) realloc(temp, sizeof(double)*(*size));

		for (int k = (*size)-1; k>=index; k-= 1)
		{
			if (k == index)
			{
				temp[k] = value;
			}		
			else
			{
				temp[k] = temp[k-1];
			}
		}
		return temp;
	}

	else
	{
		printf("I have no idea what type of array that is\n");
	}	
	return NULL;
}


int main()
{
	int array1_size = 3;
	int array2_size = 4;
	int * array1 = (int*) malloc(sizeof(int)*array1_size);
	double * array2 = (double*) malloc(sizeof(double)*array2_size);

	array1[0] = 8;
	array1[1] = 6;
	array1[2] = 7;

	array2[0] = 9.1;
	array2[1] = 1.3;
	array2[2] = 4.5;
	array2[3] = 7.2;
	
	array1 = (int*) arr_insert(sizeof(int), 12, 0, (void*) array1, &array1_size);
	array2 = (double*) arr_insert(sizeof(double), 7.5414, 1, (void*) array2, &array2_size);

	printf("%d\n\n\n\n", array1_size);
	for (int i = 0; i<array2_size; i++)
	{
		printf("%f\n", array2[i]);
	}
	
	free(array1);
	free(array2);
	
}
