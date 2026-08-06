#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    int POINTS[] = {
        1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
        1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");



    int score1 = 0;
    int score2 = 0;

    
    for (int i = 0, n = strlen(player1); i < n; i++)
    {
        char letter = toupper(player1[i]);
        int index = letter - 'A';
        if (index >= 0 && index < 26)
        {
            score1 += POINTS[index];
        }
    }



    for (int i = 0, n = strlen(player2); i < n; i++)
    {
        char letter = toupper(player2[i]);
        int index = letter - 'A';
        if (index >= 0 && index < 26)
        {
            score2 += POINTS[index];
        }
    }



    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}