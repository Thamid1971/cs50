// Implements a dictionary's functionality

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"
#define N 26

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets in hash table
// const unsigned int N = 26;

// Hash table
node *table[N];
void freememory(node *node);

unsigned int word_count = 0;

bool search(node *cursor, const char *word)
{
    if (cursor == NULL)
    {
        return false;
    }

    if (strcasecmp(cursor->word, word) == 0)
    {
        return true;
    }

    return search(cursor->next, word);
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    if (word == NULL)
    {
        return false;
    }

    unsigned int index = hash(word);

    return search(table[index], word);
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    if (word == NULL || word[0] == '\0')
    {
        return 0;
    }

    return toupper((unsigned char)word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
    {
        return false;
    }

    char buffer[LENGTH + 1];

    while (fgets(buffer, LENGTH + 1, file))
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        if (buffer[0] == '\0')
        {
            continue;
        }

        node *newNode = malloc(sizeof(node));

        if (newNode == NULL)
        {
            fclose(file);
            return false;
        }

        size_t i;

        for (i = 0; buffer[i] != '\0'; i++)
        {
            newNode->word[i] = buffer[i];
        }

        newNode->word[i] = '\0';

        unsigned int index = hash(buffer);

        newNode->next = table[index];
        table[index] = newNode;

        word_count++;
    }

    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (size_t i = 0; i < N; i++)
    {
        freememory(table[i]);
        table[i] = NULL;
    }

    return true;
}

void freememory(node *node)
{
    if (node == NULL)
    {
        return;
    }

    freememory(node->next);
    free(node);
}