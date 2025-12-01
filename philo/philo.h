/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:23:32 by zcadinot          #+#    #+#             */
/*   Updated: 2025/12/01 09:58:31 by zcadinot         ###   ########.fr       */
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
# include <sys/time.h>

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
	pthread_mutex_t meal_lock;

	struct s_simulation		*simu;
}	t_philo;

typedef struct s_simulation
{
	long				start_time;
	t_args			args;
	t_philo			*philos;
	pthread_t monitor_thread;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t meal_lock;
	int	stop_simulation;
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
void			*monitor(void *arg);

/* = action =*/

int				take_forks(t_philo *p);
int				drop_forks(t_philo *p);
int				philo_sleep(t_philo *p);
int				philo_think(t_philo *p);
int				philo_eat(t_philo *p);

/* == Utils == */

long			ft_atol(char *s);
long			get_timestamp(void);
int				print_error(char *msg);
void			print_status(t_philo *p, char *msg);
void			smart_sleep(long time);

#endif
