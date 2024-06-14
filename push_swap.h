/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:52:31 by aalissa           #+#    #+#             */
/*   Updated: 2024/03/21 17:41:52 by aalissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_node
{
	int				value;
	bool			above_mid;
	bool			cheap;
	int				price;
	size_t			pos;
	struct s_node	*next;
	struct s_node	*pre;
	struct s_node	*target;
}	t_node;

char	**ft_split(char *str, char sep);
void	pa(t_node **a, t_node **b, bool checker);
void	pb(t_node **b, t_node **a, bool checker);
void	ra(t_node **a, bool checker);
void	rb(t_node **b, bool checker);
void	rr(t_node **a, t_node **b, bool checker);
void	sa(t_node **a, bool checker);
void	sb(t_node **b, bool checker);
void	ss(t_node **a, t_node **b, bool checker);
int		ft_atoi(char *str);
void	list_init(t_node **a, char **argv, bool artificial);
void	finish_rotation(t_node **a, t_node *top, char list_name);
void	push_swap(t_node **a, t_node **b);
void	set_pos(t_node *head);
void	set_price(t_node *a, t_node *b);
void	set_cheapest(t_node *b);
void	init_nodes(t_node *a, t_node *b);
bool	sorted(t_node *head);
void	tiny_sort(t_node **a);
t_node	*create_node(int data);
void	free_list(t_node **head);
int		list_len(t_node *head);
t_node	*find_last_node(t_node *head);
t_node	*find_smallest(t_node *stack);
t_node	*return_cheapest(t_node *stack);
void	rra(t_node **a, bool checker);
void	rrb(t_node **b, bool checker);
void	rrr(t_node **a, t_node **b, bool checker);
void	add_node(t_node **stack, int nbr);
void	free_artificial(char **argv);
void	free_list(t_node **list);
void	error_free(t_node **a, char **argv, bool artificial);
int		syntax_check(char *str_nbr);
int		repetition_check(t_node *a, int nbr);

#endif
