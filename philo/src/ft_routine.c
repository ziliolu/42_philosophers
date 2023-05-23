/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:40:14 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/05/11 21:17:52 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*ft_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->info->nbr_of_philos == 1)
		return (ft_just_one_philo(philo));
	while (1)
	{
		ft_take_forks(philo);
		pthread_mutex_lock(&philo->info->any_philo_is_dead_mutex);
		pthread_mutex_lock(&philo->info->meals_complete_mutex);
		if (philo->info->any_philo_is_dead != -1 || \
		philo->info->meals_complete == philo->info->nbr_of_philos)
		{
			pthread_mutex_unlock(&philo->info->any_philo_is_dead_mutex);
			pthread_mutex_unlock(&philo->info->meals_complete_mutex);
			return (0);
		}
		pthread_mutex_unlock(&philo->info->any_philo_is_dead_mutex);
		pthread_mutex_unlock(&philo->info->meals_complete_mutex);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (0);
}

void	*ft_just_one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->first_fork);
	ft_print_msg("has taken a fork", philo, PINK);
	pthread_mutex_unlock(philo->first_fork);
	return (0);
}
