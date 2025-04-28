#include "ft_push_swap.h"

int count_words(char const *s, char c)
{
    int count;
    int i;

    count = 0;
    i = 0;
    while (s[i])
    {
        while (s[i] == c)
            i++;
        if (s[i])
            count++;
        while (s[i] && s[i] != c)
            i++;
    }
    return (count);
}

char *create_word(char const *s, int start, int end)
{
    char *word;
    int i;

    word = (char *)malloc(sizeof(char) * (end - start + 1));
    if (!word)
        return (NULL);
    i = 0;
    while (start < end)
        word[i++] = s[start++];
    word[i] = '\0';
    return (word);
}

char **free_words(char **result, int count)
{
    int i;

    i = 0;
    while (i < count)
    {
        free(result[i]);
        i++;
    }
    free(result);
    return (NULL);
}

char **ft_split(char const *s, char c)
{
    char    **result;
    int     word_count;

    if (!s)
        return (NULL);
    word_count = count_words(s, c);
    result = (char **)malloc(sizeof(char *) * (word_count + 1));
    if (!result)
        return (NULL);
    return (ft_split_continue(s, c, result, word_count));
}

char **ft_split_continue(char const *s, char c, char **result, int word_count)
{
    int i;
    int j;
    int start;

    i = 0;
    j = 0;
    while (s[i] && j < word_count)
    {
        while (s[i] == c)
            i++;
        start = i;
        while (s[i] && s[i] != c)
            i++;
        result[j] = create_word(s, start, i);
        if (!result[j])
            return (free_words(result, j));
        j++;
    }
    result[j] = NULL;
    return (result);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *str;
    size_t  i;
    size_t  s_len;

    if (!s)
        return (NULL);
    s_len = 0;
    while (s[s_len])
        s_len++;
    if (start >= s_len)
        len = 0;
    else if (len > s_len - start)
        len = s_len - start;
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    i = 0;
    while (i < len && start + i < s_len)
    {
        str[i] = s[start + i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

void free_split(char **split)
{
    int i;

    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}