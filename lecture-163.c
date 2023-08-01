#include <stdio.h>
#include <stdlib.h>


int sortAscending(int a, int b)
{
    if (a<b) return 1;
    else return 0;
}

int sortDescending(int a, int b)
{
    if (a>b) return 1;
    else return 0;
}

void sort(int **arr, int n, int (*ptr)(int,int))
{
    int temp[n];
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<n-1; i++)
        {
            if (i!=j)
            {
                if ((*ptr)((*arr)[i],(*arr)[j]))
                {
                    temp[i] = (*arr)[i];
                }
                else
                {
                    temp[j+1] = (*arr)[i]; 
                }
            }
        }
    }
    *arr = temp;
}

int main()
{
    int (*arr) = (int*) malloc(sizeof(int)*5);
    arr[0] = 1;
    arr[1] = 5;
    arr[2] = 3;
    arr[3] = 2;
    arr[4] = 0;

    sort(&arr,5,&sortAscending);
    sort(&arr,5,&sortDescending);
}