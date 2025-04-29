#include "ft_push_swap.h"

void	sort_two(t_node **a)
{
	if ((*a)->num > (*a)->next->num)
	{
		ft_sx(a);
		write(1, "sa\n", 3);
	}
}

void	sort_three(t_node **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->num;
	second = (*a)->next->num;
	third = (*a)->next->next->num;
	if (first > second && second < third && first < third)
	{
		ft_sx(a);
		write(1, "sa\n", 3);
	}
	else if (first > second && second > third)
	{
		ft_sx(a);
		write(1, "sa\n", 3);
		ft_rrx(a);
		write(1, "rra\n", 4);
	}
	else if (first > second && first > third)
	{
		ft_rx(a);
		write(1, "ra\n", 3);
	}
}

void	sort_three_continue(t_node **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->num;
	second = (*a)->next->num;
	third = (*a)->next->next->num;
	if (first < second && second > third && first < third)
	{
		ft_sx(a);
		write(1, "sa\n", 3);
		ft_rx(a);
		write(1, "ra\n", 3);
	}
	else if (first < second && second > third)
	{
		ft_rrx(a);
		write(1, "rra\n", 4);
	}
}

int	find_min_position(t_node *a)
{
	int		min;
	int		pos;
	int		min_pos;
	t_node	*tmp;

	if (!a)
		return (0);
	min = a->num;
	min_pos = 0;
	pos = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->num < min)
		{
			min = tmp->num;
			min_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return (min_pos);
}

void	rotate_to_min(t_node **a, int min_pos, int size)
{
	int	i;

	if (min_pos <= size / 2)
	{
		i = 0;
		while (i++ < min_pos)
		{
			ft_rx(a);
			write(1, "ra\n", 3);
		}
	}
	else
	{
		i = 0;
		while (i++ < size - min_pos)
		{
			ft_rrx(a);
			write(1, "rra\n", 4);
		}
	}
}

void	sort_four_five(t_node **a, t_node **b, int size)
{
	int	min_pos;

	while (size > 3)
	{
		min_pos = find_min_position(*a);
		rotate_to_min(a, min_pos, size);
		ft_px(b, a);
		write(1, "pb\n", 3);
		size--;
	}
	if (size == 3)
	{
		if (!is_sorted(*a))
		{
			sort_three(a);
			sort_three_continue(a);
		}
	}
	while (*b)
	{
		ft_px(a, b);
		write(1, "pa\n", 3);
	}
}

void	free_list(t_node *lst)
{
	t_node	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}