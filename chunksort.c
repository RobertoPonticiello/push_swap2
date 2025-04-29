/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <rpontici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:43:24 by rpontici          #+#    #+#             */
/*   Updated: 2025/03/01 17:43:24 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	find_position(t_node *lst, int value)
{
	int	pos;

	pos = 0;
	while (lst)
	{
		if (lst->num == value)
			return (pos);
		pos++;
		lst = lst->next;
	}
	return (pos);
}

void	push_chunks(t_node **a, t_node **b, int c_size, int num_chunks)
{
	int	c_chunk;
	int	list_b;

	c_chunk = 1;
	while (*a)
	{
		if (((*a)->num) < c_chunk * c_size)
		{
			ft_px(b, a);
			write(1, "pb\n", 3);
			if ((*b) && ((*b)->num < (c_chunk * c_size) - (c_size / 2)))
			{
				ft_rx(b);
				write(1, "rb\n", 3);
			}
		}
		else
		{
			ft_rx(a);
			write(1, "ra\n", 3);
		}
		list_b = ft_list_size(*b);
		if (list_b >= c_chunk * c_size && c_chunk < num_chunks)
			c_chunk = c_chunk + 1;
	}
}

void	rotate_b(t_node **b, int count, int use_rrx)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (use_rrx)
		{
			ft_rrx(b);
			write(1, "rrb\n", 4);
		}
		else
		{
			ft_rx(b);
			write(1, "rb\n", 3);
		}
		i = i + 1;
	}
}

void	pull_chunks(t_node **a, t_node **b)
{
	int	max;
	int	pos;
	int	size_b;

	while (*b)
	{
		max = find_max(*b);
		pos = find_position(*b, max);
		size_b = ft_list_size(*b);
		if (pos <= size_b / 2)
			rotate_b(b, pos, 0);
		else
			rotate_b(b, size_b - pos, 1);
		ft_px(a, b);
		write(1, "pa\n", 3);
	}
}

void	chunk_sort(t_node **a, t_node **b)
{
	int	total;
	int	num_chunks;
	int	c_size;

	total = ft_list_size(*a);
	if (total <= 100)
	{
		num_chunks = 5;
	}
	else
	{
		num_chunks = 11;
	}
	c_size = total / num_chunks + 1;
	push_chunks(a, b, c_size, num_chunks);
	pull_chunks(a, b);
}