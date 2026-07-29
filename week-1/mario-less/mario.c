#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h <= 0);

    for (int i = 1; i <= h; i++)
    {
        for (int j = i; j < h; j++)
        {
            printf(" ");
        }
        for (int p = 0; p < i; p++)
        {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}