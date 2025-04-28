/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <rpontici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:43:16 by rpontici          #+#    #+#             */
/*   Updated: 2025/04/28 19:30:28 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h> 
# include <limits.h>
# include "ft_printf.h"

typedef struct s_node
{
	int				num;
	struct s_node	*next;
}			t_node;

/* Validazione input */
int		is_valid_integer(char *str);
int		check_duplicates(int *numbers, int count);
int		ft_atoi_safe(const char *str, int *result);
int		ft_atoi_safe_continue(const char *str, int i, int sign, int *result);
int		is_sorted(t_node *lst);

/* Utility stringhe */
char	**ft_split(char const *s, char c);
char	**ft_split_continue(char const *s, char c, char **result, int word_count);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	free_split(char **split);

/* Parsing argomenti */
int		parse_arguments(int argc, char **argv, t_node **a);
int		validate_and_convert(char **split, int *numbers, int count);
int		create_list_from_numbers(int *numbers, int count, t_node **a);

/* Algoritmi di ordinamento */
void	sort_two(t_node **a);
void	sort_three(t_node **a);
void	chunk_sort(t_node **a, t_node **b);
void	normalize_list(t_node **a);

/* Operations */
void	ft_sx(t_node **nums);
void	ft_px(t_node **node, t_node **out);
void	ft_rx(t_node **node);
void	ft_rrx(t_node **node);

/* Funzioni di lista */
void	ft_node_back(t_node **lst, t_node *new);
void	ft_node_front(t_node **lst, t_node *new);
t_node	*ft_new_num(int num);
int		ft_list_size(t_node *lst);
void	free_list(t_node *lst);

/* Utility per chunk sort */
int		find_position(t_node *lst, int value);
int		find_max(t_node *lst);
void	push_chunks(t_node **a, t_node **b, int c_size, int num_chunks);
void	rotate_b(t_node **b, int count, int use_rrx);
void	pull_chunks(t_node **a, t_node **b);

/* Esistenti */
int		ft_atoi(const char *str);
int		ft_check_duplicate(int argc, char **argv);
t_node	**ft_new_nums(int argc, char **argv);
void	ft_radix_sort(t_node **a, t_node **b);

#endif