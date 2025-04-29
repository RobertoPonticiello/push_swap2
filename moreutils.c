/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moreutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <rpontici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:40:26 by rpontici          #+#    #+#             */
/*   Updated: 2025/04/29 20:40:38 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	s_len;

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

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
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
