/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:48:39 by aalissa           #+#    #+#             */
/*   Updated: 2024/03/21 19:22:52 by aalissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rota_both(t_node **a, t_node **b, t_node *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rr(a, b, false);
	set_pos(*a);
	set_pos(*b);
}

static void	rev_rota_both(t_node **a, t_node **b, t_node *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rrr(a, b, false);
	set_pos(*a);
	set_pos(*b);
}

void	finish_rotation(t_node **a, t_node *top, char list_name)
{
	while (*a != top)
	{
		if (list_name == 'a')
		{
			if (top->above_mid)
				ra(a, false);
			else
				rra(a, false);
		}
		else if (list_name == 'b')
		{
			if (top->above_mid)
				rb(a, false);
			else
				rrb(a, false);
		}
	}
}

static	void	move_nodes(t_node **a, t_node **b)
{
	t_node	*cheapest;

	cheapest = return_cheapest(*b);
	if (cheapest->above_mid && cheapest->target->above_mid)
		rota_both(a, b, cheapest);
	else if (!(cheapest->above_mid) && !(cheapest->target->above_mid))
		rev_rota_both(a, b, cheapest);
	finish_rotation(b, cheapest, 'b');
	finish_rotation(a, cheapest->target, 'a');
	pa(a, b, false);
}

void	push_swap(t_node **a, t_node **b)
{
	t_node	*smallest;
	int		len;

	len = list_len(*a);
	while (len-- > 3)
		pb(b, a, false);
	tiny_sort(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_pos(*a);
	smallest = find_smallest(*a);
	if (smallest->above_mid)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}
