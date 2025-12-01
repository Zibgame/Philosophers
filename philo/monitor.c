/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 08:48:08 by zcadinot          #+#    #+#             */
/*   Updated: 2025/12/01 10:17:12 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	all_ate(t_simulation *simu)
{
	long	i;

	if (simu->args.number_of_times_each_philosopher_must_eat <= 0)
		return (0);
	i = 0;
	while (i < simu->args.nb_philo)
	{
		if (simu->philos[i].meals < \
				simu->args.number_of_times_each_philosopher_must_eat)
			return (0);
		i++;
	}
	pthread_mutex_lock(&simu->print_lock);
	simu->stop_simulation = 1;
	pthread_mutex_unlock(&simu->print_lock);
	return (1);
}

static int	philo_is_dead(t_philo *p)
{
	long	time;
	long	last;

	pthread_mutex_lock(&p->simu->meal_lock);
	last = p->last_meal;
	pthread_mutex_unlock(&p->simu->meal_lock);
	time = get_timestamp();
	if (time - last >= p->simu->args.time_to_die)
	{
		pthread_mutex_lock(&p->simu->print_lock);
		if (!p->simu->stop_simulation)
		{
			printf("%ld %ld died\n",
				time - p->simu->start_time, p->id);
			p->simu->stop_simulation = 1;
		}
		pthread_mutex_unlock(&p->simu->print_lock);
		return (1);
	}
	return (0);
}

void	*monitor(void *arg)
{
	t_simulation	*simu;
	long			i;

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
		if (all_ate(simu))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
