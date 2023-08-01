#include <stdio.h>
#include <stdlib.h>

void thinDough(){
    printf("Thin\n");
}

void thickDough(){
    printf("Thick\n");
}

void pestoSauce(){
    printf("Pesto\n");
}

void tomatoSauce(){
    printf("Tomato\n");
}

void mozaCheese(){
    printf("Mozza\n");
}

void cheddarCheese(){
    printf("Cheddar\n");
}

void createPizza(void (*dough)(), void (*sauce)(), void (*cheese)())
{
    printf("==========================\n");
    printf("Dough: ");
    dough();
    printf("Sauce: ");
    sauce();
    printf("Cheese: ");
    cheese();
    printf("==========================\n");
}

int main()
{
    createPizza(thickDough,pestoSauce,mozaCheese);
    createPizza(thinDough,tomatoSauce,mozaCheese);
}