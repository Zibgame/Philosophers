/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 01:34:01 by zcadinot          #+#    #+#             */
/*   Updated: 2025/12/01 08:27:48 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	while (1)
	{
		take_forks(p);
		usleep(p->simu->args.time_to_eat * 1000);
		drop_forks(p);
		philo_sleep(p);
		philo_think(p);
	}
	return (NULL);
}
