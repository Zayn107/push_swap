/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rota_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:51:24 by aalissa           #+#    #+#             */
/*   Updated: 2024/03/14 14:37:54 by aalissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rota(t_node **head)
{
	t_node	*last;
	size_t	len;

	len = list_len(*head);
	if (NULL == *head || NULL == head || 1 == len)
		return ;
	last = find_last_node(*head);
	last->pre->next = NULL;
	last->next = *head;
	last->pre = NULL;
	*head = last;
	last->next->pre = last;
}

void	rra(t_node **a, bool checker)
{
	rev_rota(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_node **b, bool checker)
{
	rev_rota(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b, bool checker)
{
	rev_rota(a);
	rev_rota(b);
	if (!checker)
		write(1, "rrr\n", 4);
}
