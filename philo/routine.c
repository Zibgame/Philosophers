/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 01:34:01 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/29 02:05:40 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat(t_philo *p)
{
	pthread_mutex_lock(p->left_fork);
	pthread_mutex_lock(p->right_fork);
	p->last_meal = get_time();
	printf("Philo %ld is eating\n", p->id);
	usleep(p->simu->args.time_to_eat * 1000);
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(p->right_fork);
}

void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	while (1)
	{
		eat(p);
		printf("Philo %ld is sleeping\n", p->id);
		usleep(p->simu->args.time_to_sleep * 1000);
		printf("Philo %ld is thinking\n", p->id);
	}
	return (NULL);
}

void	monitor(t_simulation *simu)
{
	long	i;

	while (1)
	{
		i = 0;
		while (i < simu->args.nb_philo)
		{
			if (get_time() - simu->philos[i].last_meal
				> simu->args.time_to_die)
			{
				printf("%ld died\n", simu->philos[i].id);
				return ;
			}
			i++;
		}
		usleep(1000);
	}
}
