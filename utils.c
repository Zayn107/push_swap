/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:03:05 by aalissa           #+#    #+#             */
/*   Updated: 2024/03/21 19:23:55 by aalissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_last_node(t_node *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	add_node(t_node **stack, int nbr)
{
	t_node	*node;
	t_node	*last_node;

	if (NULL == stack)
		return ;
	node = malloc(sizeof(t_node));
	if (NULL == node)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (NULL == *stack)
	{
		*stack = node;
		node->pre = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->pre = last_node;
	}
}

int	list_len(t_node *head)
{
	int		len;
	t_node	*temp;

	if (head == NULL)
		return (0);
	len = 0;
	temp = head;
	while (temp != NULL)
	{
		++len;
		temp = temp->next;
	}
	return (len);
}

t_node	*find_smallest(t_node *stack)
{
	long	smallest;
	t_node	*smallest_node;

	if (NULL == stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

t_node	*return_cheapest(t_node *stack)
{
	if (NULL == stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheap)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
