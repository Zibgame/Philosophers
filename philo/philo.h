/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:23:32 by zcadinot          #+#    #+#             */
/*   Updated: 2025/12/01 08:16:07 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* == Includes == */

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* == Structures == */

typedef struct s_args
{
	long	nb_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	number_of_times_each_philosopher_must_eat;
}	t_args;

typedef struct s_philo
{
	long			id;
	long			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_simulation		*simu;
}	t_philo;

typedef struct s_simulation
{
	t_args			args;
	t_philo			*philos;
	pthread_mutex_t	*forks;
}	t_simulation;

/* == Parsing == */

int				check_args(int ac, char **av);
t_args			create_args_struct(int ac, char **av);
t_simulation	init_simulation_struct(t_args args);

/* == Simulation == */

void			init_philos(t_simulation *simu);
void			start_threads(t_simulation *simu);
void			join_threads(t_simulation *simu);
pthread_mutex_t	*create_forks_tab(t_simulation simu);
void			*routine(void *arg);

/* = action =*/

int				take_forks(t_philo *p);

/* == Utils == */

long			ft_atol(char *s);
int				print_error(char *msg);

#endif
