#include <stdio.h>
#include <stdlib.h>


void renameExtension(char * file, char * newExtension)
{
    char newString[100];
    int index = 1000;
    for (int i = 0; i<100; i++)
    {
        if (file[i] == '.')
        {
            index = i;
        }

        if (i<=index)
        {
             newString[i] = file[i];
        }
        else
        {
            newString[i] = newExtension[i-index];
            
            if (newExtension[i-index] == 0) break;
        }
    }
    rename(file, newString);
}

int main()
{
    renameExtension("myFile.csv", ".cpp");
}