#include <stdio.h>
#include <stdlib.h>

int freqAsValue(int * arr, int size, int k)
{
    int *countArray = (int*) malloc(sizeof(int)*k);
    for (int i = 0; i<size; i++)
    {
        countArray[arr[i]-1] = countArray[arr[i]-1] + 1;
    }

    for (int i = 0; i<k; i++)
    {
        if (countArray[i] != (i+1))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    const int size = 6;
    const int k = 3;
    int arr[] = {1,2,2,3,3,3};
    printf("%d\n",freqAsValue(arr, size, k));

}