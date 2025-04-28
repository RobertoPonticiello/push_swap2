#include "ft_push_swap.h"

void sort_two(t_node **a)
{
    if ((*a)->num > (*a)->next->num)
    {
        ft_sx(a);
        ft_printf("sa\n");
    }
}

void sort_three(t_node **a)
{
    int first;
    int second;
    int third;

    first = (*a)->num;
    second = (*a)->next->num;
    third = (*a)->next->next->num;

    if (first > second && second < third && first < third)
    {
        ft_sx(a);
        ft_printf("sa\n");
    }
    else if (first > second && second > third)
    {
        ft_sx(a);
        ft_printf("sa\n");
        ft_rrx(a);
        ft_printf("rra\n");
    }
    else if (first > second && first > third)
    {
        ft_rx(a);
        ft_printf("ra\n");
    }
    else if (first < second && second > third && first < third)
    {
        ft_sx(a);
        ft_printf("sa\n");
        ft_rx(a);
        ft_printf("ra\n");
    }
    else if (first < second && second > third)
    {
        ft_rrx(a);
        ft_printf("rra\n");
    }
}

void free_list(t_node *lst)
{
    t_node *tmp;

    while (lst)
    {
        tmp = lst;
        lst = lst->next;
        free(tmp);
    }
}
