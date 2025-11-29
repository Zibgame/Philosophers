/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 01:49:15 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/29 01:52:42 by zcadinot         ###   ########.fr       */
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
}
