#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (argv[1][i] < '0' || argv[1][i] > '9')
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);

    if (key == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string text = get_string("Plaintext:");

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isupper(text[i]))
        {
            text[i] = ((text[i] - 'A') + key) % 26 + 'A';
        }
        else if (islower(text[i]))
        {
            text[i] = ((text[i] - 'a') + key) % 26 + 'a';
        }

        continue;
    }

    printf("ciphertext:%s\n", text);

    return 0;
}