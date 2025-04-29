/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moremoreutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <rpontici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:34:39 by rpontici          #+#    #+#             */
/*   Updated: 2025/04/29 20:40:19 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	parse_arguments(int argc, char **argv, t_node **a)
{
	char	**split;
	int		result;

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
