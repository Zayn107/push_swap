/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_price.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:01:32 by aalissa           #+#    #+#             */
/*   Updated: 2024/03/21 19:24:44 by aalissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_pos(t_node *head)
{
	int	i;
	int	center_line;

	i = 0;
	if (head == NULL)
		return ;
	center_line = list_len(head) / 2;
	while (head)
	{
		head->pos = i;
		if (i <= center_line)
			head->above_mid = true;
		else
			head->above_mid = false;
		head = head->next;
		++i;
	}
}

static void	target_node(t_node *a, t_node *b)
{
	t_node	*target;
	t_node	*current_a;
	long	best_match;

	while (b)
	{
		best_match = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (b->value < current_a->value && current_a->value < best_match)
			{
				target = current_a;
				best_match = current_a->value;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match)
			b->target = find_smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	set_price(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_b = list_len(b);
	len_a = list_len(a);
	while (b)
	{
		b->price = b->pos;
		if (!(b->above_mid))
			b->price = len_b - (b->pos);
		if (b->target->above_mid)
			b->price += b->target->pos;
		else
			b->price += len_a - (b->target->pos);
		b = b->next;
	}
}

void	set_cheapest(t_node *b)
{
	long	best_match_value;
	t_node	*best_match_node;

	if (NULL == b)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->price < best_match_value)
		{
			best_match_value = b->price;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheap = true;
}

void	init_nodes(t_node *a, t_node *b)
{
	set_pos(a);
	set_pos(b);
	target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}
