/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:23:32 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/29 00:12:57 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>

/* == Struct == */

typedef struct s_args
{
	long	number_of_philosophers;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	number_of_times_each_philosopher_must_eat;
}	t_args;

/* == Main == */

/* == Parsing == */

t_args	create_args_struct(int argc, char **argv);
int		check_args(int ac, char **av);

/* == Other == */

int		print_error(char *msg);
long	ft_atol(char *s);

#endif
