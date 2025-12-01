/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 01:49:15 by zcadinot          #+#    #+#             */
/*   Updated: 2025/12/01 09:26:54 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_threads(t_simulation *simu)
{
	long	i;

	i = 0;
	while (i < simu->args.nb_philo)
	{
		pthread_create(&simu->philos[i].thread, NULL,
			routine, &simu->philos[i]);
		i++;
	}
	pthread_create(&simu->monitor_thread, NULL, monitor, simu);
}

void	join_threads(t_simulation *simu)
{
	long	i;

	i = 0;
	while (i < simu->args.nb_philo)
	{
		pthread_join(simu->philos[i].thread, NULL);
		i++;
	}
	pthread_join(simu->monitor_thread, NULL);
}
