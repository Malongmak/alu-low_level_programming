#include "main.h"

/**
 * count_words - counts the number of words in a string
 * @str: the string to count words in
 *
 * Return: the number of words
 */
int count_words(char *str)
{
    int count = 0, in_word = 0;

    while (*str)
    {
        if (*str == ' ')
        {
            in_word = 0;
        }
        else if (!in_word)
        {
            in_word = 1;
            count++;
        }
        str++;
    }
    return (count);
}

/**
 * strtow - splits a string into words
 * @str: the string to split
 *
 * Return: a pointer to an array of strings (words), or NULL on failure
 */
char **strtow(char *str)
{
    char **words, *word_start;
    int i, k, word_len, word_count;

    if (str == NULL || *str == '\0')
        return (NULL);

    word_count = count_words(str);
    if (word_count == 0)
        return (NULL);

    words = malloc((word_count + 1) * sizeof(char *));
    if (words == NULL)
        return (NULL);

    for (i = 0; i < word_count; i++)
    {
        while (*str == ' ')
            str++;
        word_start = str;
        word_len = 0;
        while (*str && *str != ' ')
        {
            word_len++;
            str++;
        }
        words[i] = malloc((word_len + 1) * sizeof(char));
        if (words[i] == NULL)
        {
            for (k = 0; k < i; k++)
                free(words[k]);
            free(words);
            return (NULL);
        }
        for (k = 0; k < word_len; k++)
            words[i][k] = word_start[k];
        words[i][word_len] = '\0';
    }
    words[word_count] = NULL;
    return (words);
}

