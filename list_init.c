/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:07:24 by aalissa           #+#    #+#             */
/*   Updated: 2024/03/14 14:31:30 by aalissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(char *str)
{
	int		s;
	size_t	i;
	long	temp;

	temp = 0;
	i = 0;
	s = 1;
	while (((8 <= str[i]) && (str[i] <= 13)) || str[i] == ' ')
		++i;
	if (str[i] == '-')
	{
		s = -1;
		++i;
	}
	else if (str[i] == '+')
		++i;
	while (('0' <= str[i]) && (str[i] <= '9'))
	{
		temp = temp * 10 + (str[i] - '0');
		++i;
	}
	return (temp * s);
}

void	list_init(t_node **a, char **argv, bool artificial)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (syntax_check(argv[i]))
			error_free(a, argv, artificial);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, artificial);
		if (repetition_check(*a, (int)nbr))
			error_free(a, argv, artificial);
		add_node(a, (int)nbr);
		++i;
	}
	if (artificial)
		free_artificial(argv);
}
