/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:43:19 by rpontici          #+#    #+#             */
/*   Updated: 2025/04/28 17:21:57 by marvin           ###   ########.fr       */
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

t_node	*ft_new_num(int num)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->num = num;
	new_node->next = NULL;
	return (new_node);
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

#include "ft_push_swap.h"

int main(int argc, char **argv)
{
    t_node  *a;
    t_node  *b;
    int     size;

    b = NULL;
    if (argc < 2)
        return (0);
    if (!parse_arguments(argc, argv, &a))
    {
        ft_printf("Error\n");
        return (0);
    }
    if (is_sorted(a))
    {
        free_list(a);
        return (0);
    }
    size = ft_list_size(a);
    if (size == 2)
        sort_two(&a);
    else if (size == 3)
        sort_three(&a);
    else
    {
        normalize_list(&a);
        chunk_sort(&a, &b);
    }
    free_list(a);
    return (0);
}

