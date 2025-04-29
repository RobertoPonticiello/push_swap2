/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <rpontici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:43:19 by rpontici          #+#    #+#             */
/*   Updated: 2025/04/29 20:24:04 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_check_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc)
		{
			if (ft_atoi(argv[j]) == ft_atoi(argv[i]) && j != i)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_node	**ft_new_nums(int argc, char **argv)
{
	t_node	**nums;
	int		i;

	nums = malloc(sizeof(t_node *) * argc);
	i = 0;
	while (i + 1 < argc)
	{
		if (i == 0)
			nums[i] = ft_new_num(ft_atoi(argv[i + 1]));
		else
		{
			nums[i] = ft_new_num(ft_atoi(argv[i + 1]));
			ft_node_back(nums, nums[i]);
		}
		i++;
	}
	return (nums);
}

int	init_and_validate(int argc, char **argv, t_node **a)
{
	if (!parse_arguments(argc, argv, a))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (ft_list_size(*a) == 1 || is_sorted(*a))
	{
		free_list(*a);
		return (0);
	}
	return (1);
}

void	apply_sorting_algorithm(t_node **a, t_node **b, int size)
{
	if (size == 2)
		sort_two(a);
	else if (size == 3)
	{
		sort_three(a);
		sort_three_continue(a);
	}
	else if (size <= 5)
		sort_four_five(a, b, size);
	else
	{
		normalize_list(a);
		chunk_sort(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		size;

	b = NULL;
	if (argc < 2)
		return (0);
	if (!init_and_validate(argc, argv, &a))
		return (0);
	size = ft_list_size(a);
	apply_sorting_algorithm(&a, &b, size);
	free_list(a);
	return (0);
}
