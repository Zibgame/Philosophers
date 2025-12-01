/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 01:34:01 by zcadinot          #+#    #+#             */
/*   Updated: 2025/12/01 10:07:10 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->simu->args.nb_philo == 1)
	{
		print_status(p, "has taken a fork\n");
		while (!p->simu->stop_simulation)
			usleep(100);
		return (NULL);
	}
	while (!p->simu->stop_simulation)
	{
		if (!take_forks(p))
			break ;
		if (!philo_eat(p))
			break ;
		if (!drop_forks(p))
			break ;
		if (!philo_sleep(p))
			break ;
		if (!philo_think(p))
			break ;
	}
	return (NULL);
}
