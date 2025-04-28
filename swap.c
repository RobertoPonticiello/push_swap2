/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <rpontici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:43:10 by rpontici          #+#    #+#             */
/*   Updated: 2025/03/01 17:43:10 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	r;

	r = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		r = r * 10 + *str - '0';
		str++;
	}
	return (sign * r);
}

void	ft_sx(t_node **lst)
{
	t_node	*first;
	t_node	*second;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	first = *lst;
	second = (*lst)->next;
	first->next = second->next;
	second->next = first;
	*lst = second;
}

void	ft_px(t_node **dest, t_node **src)
{
	t_node	*temp;

	if (!src || !*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
}

void	ft_rx(t_node **node)
{
	t_node	*first;
	t_node	*temp;

	if (!node || !*node || !(*node)->next)
		return ;
	first = *node;
	*node = (*node)->next;
	first->next = NULL;
	temp = *node;
	while (temp->next)
		temp = temp->next;
	temp->next = first;
}

void	ft_rrx(t_node **node)
{
	t_node	*last;
	t_node	*temp;

	if (!node || !*node || !(*node)->next)
		return ;
	last = *node;
	while (last->next)
		last = last->next;
	temp = *node;
	while (temp->next->next)
		temp = temp->next;
	last->next = node[0];
	*node = last;
	temp->next = NULL;
}
