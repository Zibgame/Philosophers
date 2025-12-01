/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 07:59:25 by zcadinot          #+#    #+#             */
/*   Updated: 2025/12/01 08:25:59 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks(t_philo *p)
{
	if (pthread_mutex_lock(p->left_fork) != 0)
	{
		return (0);
	}
	printf("has taken a fork\n");
	if (pthread_mutex_lock(p->right_fork) != 0)
	{
		return (0);
	}
	printf("has taken a fork\n");
	return (1);
}

int	drop_forks(t_philo *p)
{
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(p->right_fork);
	printf("has dropped forks\n");
	return (1);
}

int	philo_sleep(t_philo *p)
{
	printf("is sleeping\n");
	usleep(p->simu->args.time_to_sleep * 1000);
	return (1);
}

int	philo_think(t_philo *p)
{
	(void) p;
	printf("is thinking\n");
	return (1);
}
