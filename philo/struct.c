/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 23:27:27 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/28 23:55:14 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_args	create_args_struct(int argc, char **argv)
{
	t_args	args;

	args.number_of_philosophers = ft_atol(argv[1]);
	args.time_to_die = ft_atol(argv[2]);
	args.time_to_eat = ft_atol(argv[3]);
	args.time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		args.number_of_times_each_philosopher_must_eat = ft_atol(argv[5]);
	else if (argc >= 5)
		args.number_of_times_each_philosopher_must_eat = 0;
	return (args);
}
