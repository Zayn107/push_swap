/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rota_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:27:22 by aalissa           #+#    #+#             */
/*   Updated: 2024/03/14 14:38:56 by aalissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rota(t_node **head)
{
	t_node	*last_node;
	size_t	len;

	len = list_len(*head);
	if (NULL == head || NULL == *head || 1 == len)
		return ;
	last_node = find_last_node(*head);
	last_node->next = *head;
	*head = (*head)->next;
	(*head)->pre = NULL;
	last_node->next->pre = last_node;
	last_node->next->next = NULL;
}

void	ra(t_node **a, bool checker)
{
	rota(a);
	if (!checker)
		write(1, "ra\n", 3);
}

void	rb(t_node **b, bool checker)
{
	rota(b);
	if (!checker)
		write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b, bool checker)
{
	rota(a);
	rota(b);
	if (!checker)
		write (1, "rr\n", 3);
}
