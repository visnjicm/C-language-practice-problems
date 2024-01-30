#include <stdio.h>
#include <stdlib.h>


void replaceSpace(char * filename)
{
    char newString[1000];
    char newChar;
    int index=0;
    FILE *ptr = fopen(filename, "r");

    for (int i = 0; i<1000; i++)
    {
        newChar = fgetc(ptr);
        if (newChar > 0)
        {
            if (newChar != ' ')
            {
                newString[index] = newChar;
                index++;
            }
        }
        else
        {
            newString[index] = 0;
            break;
        }
    }
    fclose(ptr);

    ptr = fopen(filename, "w");

    for (int i = 0; i<1000; i++)
    {
        if (newString[i] != 0)
        {
            fputc(newString[i], ptr);
        }
        else
        {
            break;
        }
    }

    fclose(ptr);
}

int main()
{
    replaceSpace("myFile.txt");
}
