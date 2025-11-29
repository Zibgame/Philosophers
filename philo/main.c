/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:20:00 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/29 01:53:20 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_args			args;
	t_simulation	simu;

	if (argc <= 4 || argc > 6)
		return (print_error("Error: wrong number of arguments\n"));
	if (!check_args(argc, argv))
		return (print_error("Error: Wrong type of arguments\n"));
	args = create_args_struct(argc, argv);
	simu = init_simulation_struct(args);
	if (!simu.philos || !simu.forks)
		return (print_error("Fatal malloc error\n"));
	init_philos(&simu);
	start_threads(&simu);
	join_threads(&simu);
	return (0);
}
