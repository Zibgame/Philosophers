/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 07:59:25 by zcadinot          #+#    #+#             */
/*   Updated: 2025/12/01 08:09:55 by zcadinot         ###   ########.fr       */
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
