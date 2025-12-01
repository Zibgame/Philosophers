/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 08:38:29 by zcadinot          #+#    #+#             */
/*   Updated: 2025/12/01 09:59:22 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *p, char *msg)
{
	pthread_mutex_lock(&p->simu->print_lock);
	if (p->simu->stop_simulation == 0)
		printf("%ld %ld %s", get_timestamp() - p->simu->start_time, p->id, msg);
	pthread_mutex_unlock(&p->simu->print_lock);
}

void	smart_sleep(long time)
{
	long	start;

	start = get_timestamp();
	while ((get_timestamp() - start) < time)
		usleep(100);
}
