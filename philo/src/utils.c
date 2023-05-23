/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:50:40 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/05/11 21:18:00 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	ft_check_deaths(t_info *info)
{
	pthread_mutex_lock(&info->any_philo_is_dead_mutex);
	if (info->any_philo_is_dead != -1)
		printf(RED "%lld %d died\n", \
		ft_get_time() - info->start_time, info->any_philo_is_dead);
	pthread_mutex_unlock(&info->any_philo_is_dead_mutex);
}

void	ft_pair_philo(t_info *info, int i)
{
	info->philos[i].first_fork = &info->forks[i];
	info->philos[i].second_fork = &info->forks[(i + 1) \
	% info->nbr_of_philos];
}

void	ft_odd_philo(t_info *info, int i)
{
	info->philos[i].first_fork = &info->forks[(i + 1) \
	% info->nbr_of_philos];
	info->philos[i].second_fork = &info->forks[i];
}

void	ft_init_info_mutexes(t_info *info)
{
	pthread_mutex_t	can_die;
	pthread_mutex_t	meals_complete_mutex;
	pthread_mutex_t	last_meal_mutex;
	pthread_mutex_t	print_lock_mutex;
	pthread_mutex_t	any_philo_is_dead_mutex;

	pthread_mutex_init(&can_die, NULL);
	pthread_mutex_init(&meals_complete_mutex, NULL);
	pthread_mutex_init(&last_meal_mutex, NULL);
	pthread_mutex_init(&print_lock_mutex, NULL);
	pthread_mutex_init(&any_philo_is_dead_mutex, NULL);
	info->can_die = can_die;
	info->meals_complete_mutex = meals_complete_mutex;
	info->last_meal_mutex = last_meal_mutex;
	info->print_lock_mutex = print_lock_mutex;
	info->any_philo_is_dead_mutex = any_philo_is_dead_mutex;
}
