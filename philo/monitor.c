/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 08:48:08 by zcadinot          #+#    #+#             */
/*   Updated: 2025/12/01 10:08:23 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_is_dead(t_philo *p)
{
	long	time;

	time = get_timestamp();
	if (time - p->last_meal >= p->simu->args.time_to_die)
	{
		pthread_mutex_lock(&p->simu->print_lock);
		printf("%ld %ld died\n", time - p->simu->start_time, p->id);
		p->simu->stop_simulation = 1;
		pthread_mutex_unlock(&p->simu->print_lock);
		return (1);
	}
	return (0);
}

void	*monitor(void *arg)
{
	t_simulation	*simu;
	int				i;

	simu = (t_simulation *)arg;
	while (!simu->stop_simulation)
	{
		i = 0;
		while (i < simu->args.nb_philo)
		{
			if (philo_is_dead(&simu->philos[i]))
				return (NULL);
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
