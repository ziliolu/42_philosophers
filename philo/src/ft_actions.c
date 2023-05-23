/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:09:19 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/05/11 21:17:21 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->first_fork);
	ft_print_msg("has taken a fork", philo, PINK);
	pthread_mutex_lock(philo->second_fork);
	ft_print_msg("has taken a fork", philo, PINK);
	ft_eat(philo);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->last_meal_mutex);
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(&philo->info->last_meal_mutex);
	ft_print_msg("is eating", philo, YELLOW);
	usleep(philo->info->time_to_eat * 1000);
	pthread_mutex_unlock(philo->second_fork);
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_lock(&philo->info->meals_complete_mutex);
	philo->nbr_of_meals++;
	if (philo->nbr_of_meals == philo->info->times_each_philo_must_eat)
		philo->info->meals_complete++;
	pthread_mutex_unlock(&philo->info->meals_complete_mutex);
}

void	ft_think(t_philo *philo)
{
	ft_print_msg("is thinking", philo, RESET);
}

void	ft_sleep(t_philo *philo)
{
	ft_print_msg("is sleeping", philo, CIANO);
	usleep(philo->info->time_to_sleep * 1000);
}
