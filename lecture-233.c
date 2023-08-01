#include <stdio.h>
#include <stdlib.h>


int main()
{
    int a = 2302;
    int b = 1394;

    b = b | (a<<16);
    a = a | (b<<16);

    b = (b>>16);
    a = (a>>16);

    printf("%d\n",a);
    printf("%d\n",b);

}