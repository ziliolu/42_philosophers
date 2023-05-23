/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_can_continue.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:43:13 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/05/11 21:17:28 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_can_continue(t_info *info)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < info->nbr_of_philos)
		{
			pthread_mutex_lock(&info->meals_complete_mutex);
			if ((info->meals_complete == info->nbr_of_philos) || \
			ft_dead_philos(&info->philos[i]) != -1)
			{
				pthread_mutex_unlock(&info->meals_complete_mutex);
				pthread_mutex_lock(&info->print_lock_mutex);
				info->print_lock = 1;
				pthread_mutex_unlock(&info->print_lock_mutex);
				pthread_mutex_lock(&info->any_philo_is_dead_mutex);
				info->any_philo_is_dead = ft_dead_philos(&info->philos[i]);
				pthread_mutex_unlock(&info->any_philo_is_dead_mutex);
				return (-1);
			}
			pthread_mutex_unlock(&info->meals_complete_mutex);
			i++;
		}
	}
	return (1);
}

int	ft_dead_philos(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->last_meal_mutex);
	if ((ft_get_time() - philo->last_meal) > philo->info->time_to_die)
	{
		pthread_mutex_unlock(&philo->info->last_meal_mutex);
		return (philo->id);
	}
	pthread_mutex_unlock(&philo->info->last_meal_mutex);
	return (-1);
}
