/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:29:35 by zcadinot          #+#    #+#             */
/*   Updated: 2025/12/01 10:29:47 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_simulation(t_simulation *simu)
{
	long	i;

	if (!simu || !simu->forks)
		return ;
	i = 0;
	while (i < simu->args.nb_philo)
	{
		pthread_mutex_destroy(&simu->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&simu->print_lock);
	pthread_mutex_destroy(&simu->meal_lock);
	free(simu->forks);
	free(simu->philos);
}
