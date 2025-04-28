#include "ft_push_swap.h"

int process_split_args(char **split, t_node **a)
{
    int     count;
    int     *numbers;

    count = 0;
    while (split[count])
        count++;
    if (count == 0)
        return (0);
    numbers = (int *)malloc(sizeof(int) * count);
    if (!numbers)
        return (0);
    if (!validate_and_convert(split, numbers, count))
    {
        free(numbers);
        return (0);
    }
    if (!create_list_from_numbers(numbers, count, a))
    {
        free(numbers);
        return (0);
    }
    free(numbers);
    return (1);
}

int validate_and_convert(char **split, int *numbers, int count)
{
    int i;

    i = 0;
    while (i < count)
    {
        if (!is_valid_integer(split[i]) || 
            !ft_atoi_safe(split[i], &numbers[i]))
            return (0);
        i++;
    }
    if (check_duplicates(numbers, count))
        return (0);
    return (1);
}

int create_list_from_numbers(int *numbers, int count, t_node **a)
{
    int     i;
    t_node  *new_node;

    i = 0;
    while (i < count)
    {
        new_node = ft_new_num(numbers[i]);
        if (!new_node)
        {
            free_list(*a);
            *a = NULL;
            return (0);
        }
        ft_node_back(a, new_node);
        i++;
    }
    return (1);
}

int process_direct_args(int argc, char **argv, t_node **a)
{
    int     *numbers;
    int     i;

    numbers = (int *)malloc(sizeof(int) * (argc - 1));
    if (!numbers)
        return (0);
    i = 1;
    while (i < argc)
    {
        if (!is_valid_integer(argv[i]) || 
            !ft_atoi_safe(argv[i], &numbers[i - 1]))
        {
            free(numbers);
            return (0);
        }
        i++;
    }
    if (check_duplicates(numbers, argc - 1))
    {
        free(numbers);
        return (0);
    }
    if (!create_list_from_numbers(numbers, argc - 1, a))
    {
        free(numbers);
        return (0);
    }
    free(numbers);
    return (1);
}

int parse_arguments(int argc, char **argv, t_node **a)
{
    char **split;
    int  result;

    *a = NULL;
    if (argc == 2)
    {
        split = ft_split(argv[1], ' ');
        if (!split)
            return (0);
        result = process_split_args(split, a);
        free_split(split);
        return (result);
    }
    else
        return (process_direct_args(argc, argv, a));
}