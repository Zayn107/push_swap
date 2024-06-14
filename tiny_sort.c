/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:42:39 by aalissa           #+#    #+#             */
/*   Updated: 2024/03/14 14:41:44 by aalissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sorted(t_node *head)
{
	if (NULL == head)
		return (1);
	while (head->next)
	{
		if (head->value > head->next->value)
			return (false);
		head = head->next;
	}
	return (true);
}

static	t_node	*biggest(t_node *head)
{
	int		biggest;
	t_node	*biggest_node;

	if (head == NULL)
		return (NULL);
	biggest = INT_MIN;
	while (head)
	{
		if (head->value > biggest)
		{
			biggest = head->value;
			biggest_node = head;
		}
		head = head->next;
	}
	return (biggest_node);
}

void	tiny_sort(t_node **a)
{
	t_node	*biggest_node;

	biggest_node = biggest(*a);
	if (*a == biggest_node)
		ra(a, false);
	else if ((*a)->next == biggest_node)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}
