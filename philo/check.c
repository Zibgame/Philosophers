/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 00:01:23 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/29 00:09:59 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	is_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!is_digit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_valid(char *s)
{
	long	nb;

	if (!is_number(s))
		return (0);
	nb = ft_atol(s);
	if (nb <= 0 || nb > INT_MAX)
		return (0);
	return (1);
}

int	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_valid(av[i]))
			return (0);
		i++;
	}
	return (1);
}
