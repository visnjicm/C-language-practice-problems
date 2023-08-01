#include <stdio.h>
#include <stdlib.h>

typedef struct point
{
    int x;
    int y;
} Point;

int main()
{
    Point p[4] = {{3,4},{2,4}, {8,6}, {9,3}};
    FILE *ptr = fopen("myFile.bin", "wb");
    if (ptr != NULL)
    {
        fwrite(&p, sizeof(Point), 4, ptr);
    }
    return 0;
    fclose(ptr);

}