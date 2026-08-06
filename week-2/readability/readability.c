#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text:");

    int words = 1;
    int letters = 0;
    int sentence = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        text[i] = toupper(text[i]);
        int index = text[i] - 'A';
        if (index >= 0 && index < 26)
        {
            letters++;
        }
        else if (text[i] == ' ')
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence++;
        }
    }

    float L = ((float)letters / words) * 100;
    float S = ((float)sentence / words) * 100;

    int grade = round(0.0588 * L - 0.296 * S - 15.8);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }

    return 0;
}
