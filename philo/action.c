/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 07:59:25 by zcadinot          #+#    #+#             */
/*   Updated: 2025/12/01 09:55:38 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks(t_philo *p)
{
	if (p->id % 2 == 0)
	{
		pthread_mutex_lock(p->right_fork);
		print_status(p, "has taken a fork\n");
		pthread_mutex_lock(p->left_fork);
		print_status(p, "has taken a fork\n");
	}
	else
	{
		pthread_mutex_lock(p->left_fork);
		print_status(p, "has taken a fork\n");
		pthread_mutex_lock(p->right_fork);
		print_status(p, "has taken a fork\n");
	}
	return (1);
}

int	drop_forks(t_philo *p)
{
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(p->right_fork);
	print_status(p, "has dropped forks\n");
	return (1);
}

int	philo_sleep(t_philo *p)
{
	print_status(p, "is sleeping\n");
	smart_sleep(p->simu->args.time_to_sleep);
	return (1);
}

int	philo_think(t_philo *p)
{
	(void) p;
	print_status(p, "is thinking\n");
	return (1);
}

int	philo_eat(t_philo *p)
{
	pthread_mutex_lock(&p->simu->meal_lock);
	p->last_meal = get_timestamp();
	pthread_mutex_unlock(&p->simu->meal_lock);
	print_status(p, "is eating\n");
	smart_sleep(p->simu->args.time_to_eat);
	return (1);
}
