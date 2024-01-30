#include <stdio.h>
#include <stdlib.h>

typedef struct employee{
    char name[10];
    float age;
    int id;
} Employee;

Employee * firstFunction(int arraySize)
{
    Employee *temp;
    temp = (Employee*) malloc(sizeof(Employee)*arraySize);

    for (int i = 0; i<arraySize; i++)
    {
        printf("Employee #%d name: ", i);
        scanf("%s", &temp[i].name);
        printf("Employee #%d age: ", i);
        scanf("%f", &temp[i].age);
        printf("Employee #%d id: ", i);
        scanf("%d", &temp[i].id);
    }

    return temp;
}


void secondFunction(int arraySize, Employee * array)
{
    for (int i = 0; i<arraySize; i++)
    {
        printf("Employee #%d name: ", i);
        scanf("%s", &array[i].name);
        printf("Employee #%d age: ", i);
        scanf("%f", &array[i].age);
        printf("Employee #%d id: ", i);
        scanf("%d", &array[i].id);

    }
}



int main()
{
    int arraySize;
    printf("How many employees would you like to add?:\n");
    scanf("%d", &arraySize);
    Employee *array1;
    Employee *array2;
    array2 = (Employee*) malloc(sizeof(Employee)*arraySize);


    array1 = firstFunction(arraySize);
    secondFunction(arraySize, array2);

    printf("Result of first function:\n\n");

    for (int i = 0; i <arraySize; i++)
    {
        printf("Employee #%d name: %s\n", i, array1[i].name);
        printf("Employee #%d age: %f\n", i, array1[i].age);
        printf("Employee #%d id: %d\n", i, array1[i].id);
    }


    printf("Result of second function:\n\n");

    for (int i = 0; i <arraySize; i++)
    {
        printf("Employee #%d name: %s\n", i, array2[i].name);
        printf("Employee #%d age: %f\n", i, array2[i].age);
        printf("Employee #%d id: %d\n", i, array2[i].id);
    }
    free(array1);
    free(array2);
}
