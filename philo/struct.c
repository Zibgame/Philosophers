/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 23:27:27 by zcadinot          #+#    #+#             */
/*   Updated: 2025/12/01 10:15:05 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_args	create_args_struct(int argc, char **argv)
{
	t_args	args;

	args.nb_philo = ft_atol(argv[1]);
	args.time_to_die = ft_atol(argv[2]);
	args.time_to_eat = ft_atol(argv[3]);
	args.time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		args.number_of_times_each_philosopher_must_eat = ft_atol(argv[5]);
	else if (argc >= 5)
		args.number_of_times_each_philosopher_must_eat = 0;
	return (args);
}

t_simulation	init_simulation_struct(t_args args)
{
	t_simulation	simu;

	simu.args = args;
	simu.philos = malloc(sizeof(t_philo) * args.nb_philo);
	if (!simu.philos)
		return (simu);
	simu.forks = create_forks_tab(simu);
	if (!simu.forks)
	{
		free(simu.philos);
		simu.philos = NULL;
	}
	simu.start_time = get_timestamp();
	simu.stop_simulation = 0;
	pthread_mutex_init(&simu.print_lock, NULL);
	pthread_mutex_init(&simu.meal_lock, NULL);
	return (simu);
}
