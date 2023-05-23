/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:21:45 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/05/11 21:17:34 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//pthread_mutex_destroy(&root.counter->mutex);

#include "../includes/philo.h"

void	ft_destroy_all(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nbr_of_philos)
	{
		pthread_mutex_destroy(&info->forks[i]);
		i++;
	}
	if (info->forks)
		free(info->forks);
	if (info->philos)
		free(info->philos);
	pthread_mutex_destroy(&info->can_die);
	pthread_mutex_destroy(&info->meals_complete_mutex);
	pthread_mutex_destroy(&info->last_meal_mutex);
	pthread_mutex_destroy(&info->print_lock_mutex);
	pthread_mutex_destroy(&info->any_philo_is_dead_mutex);
	exit(0);
}
