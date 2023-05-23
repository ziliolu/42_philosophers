/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:54:15 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/05/11 21:17:56 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_info	info;
	int		i;

	if (ft_check_args(argc, argv) == 1)
	{
		ft_init_structs(&info, argc, argv);
		ft_can_continue(&info);
		ft_check_deaths(&info);
		i = 0;
		while (i < info.nbr_of_philos)
		{
			if (pthread_join(info.philos[i].th, NULL) != 0)
			{
				ft_print_error("error to join the thread");
				return (-1);
			}
			i++;
		}
		ft_destroy_all(&info);
	}
	return (0);
}
