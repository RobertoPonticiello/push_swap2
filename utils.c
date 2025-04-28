/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <rpontici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:43:13 by rpontici          #+#    #+#             */
/*   Updated: 2025/03/01 17:43:13 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	*list_to_array(t_node *lst, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (lst)
	{
		arr[i] = lst->num;
		i++;
		lst = lst->next;
	}
	return (arr);
}

static void	apply_normalization(t_node *lst, int *arr, int size)
{
	int	norm;

	while (lst)
	{
		norm = 0;
		while (norm < size && arr[norm] != lst->num)
			norm++;
		lst->num = norm;
		lst = lst->next;
	}
}

void	normalize_list(t_node **a)
{
	int	size;
	int	*arr;

	size = ft_list_size(*a);
	if (size <= 0)
		return ;
	arr = list_to_array(*a, size);
	if (!arr)
		return ;
	sort_array(arr, size);
	apply_normalization(*a, arr, size);
	free(arr);
}

int	find_max(t_node *lst)
{
	int	max;

	max = lst->num;
	while (lst)
	{
		if (lst->num > max)
			max = lst->num;
		lst = lst->next;
	}
	return (max);
}
