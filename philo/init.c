/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 01:24:57 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/29 01:46:16 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*create_forks_tab(t_simulation simu)
{
	pthread_mutex_t	*forks_tab;
	long			i;

	forks_tab = malloc(sizeof(pthread_mutex_t) * simu.args.nb_philo);
	if (!forks_tab)
		return (NULL);
	i = 0;
	while (i < simu.args.nb_philo)
	{
		pthread_mutex_init(&forks_tab[i], NULL);
		i++;
	}
	return (forks_tab);
}

void	init_philos(t_simulation *simu)
{
	long	i;

	i = 0;
	while (i < simu->args.nb_philo)
	{
		simu->philos[i].id = i;
		simu->philos[i].left_fork = &simu->forks[i];
		simu->philos[i].right_fork = &simu->forks[(i + 1)
			% simu->args.nb_philo];
		i++;
	}
}
