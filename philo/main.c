/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:20:00 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/29 00:11:26 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_args	args;

	if (argc <= 4 || argc > 6)
		return (print_error("Error: wrong number of arguments\n"));
	if (!check_args(argc, argv))
		return (print_error("Error: Wrong type of arguments\n"));
	args = create_args_struct(argc, argv);
	(void)args;
	return (0);
}
