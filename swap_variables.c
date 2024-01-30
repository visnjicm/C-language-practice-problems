#include <stdio.h>
#include <stdlib.h>
#include <math.h>



 void SwapFunction(int* ptrA, int* ptrB);


int main()
{
	//Enter code here
	//a = a-b
	//b = b+a
	//a = (a-b)*-1
	int a,b;
	a = 56;
	b = 30;
	SwapFunction(&a, &b);

	printf("%d%d", a, b);
		


	return 0;
}


void SwapFunction(int* ptrA, int* ptrB)
{
	*ptrA = *ptrA - *ptrB;
	*ptrB = *ptrB + *ptrA;
	*ptrA = (*ptrA - *ptrB)*(-1);
}
