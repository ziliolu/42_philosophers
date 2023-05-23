/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_structs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:29:58 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/05/11 21:17:43 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_structs(t_info *info, int argc, char **argv)
{
	ft_init_info_mutexes(info);
	ft_init_info(info, argc, argv);
	ft_init_philosophers(info);
}

void	ft_init_info(t_info *info, int argc, char **argv)
{
	info->nbr_of_philos = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->times_each_philo_must_eat = ft_atoi(argv[5]);
	else
		info->times_each_philo_must_eat = -1;
	info->any_philo_is_dead = -1;
	info->meals_complete = 0;
	info->forks = ft_init_forks(info);
	info->print_lock = -1;
}

pthread_mutex_t	*ft_init_forks(t_info *info)
{
	int				i;
	pthread_mutex_t	*forks;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * info->nbr_of_philos + 1);
	if (!forks)
		return (NULL);
	while (i < info->nbr_of_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

void	ft_init_philosophers(t_info *info)
{
	int	i;

	i = 0;
	info->philos = malloc(sizeof(t_philo) * info->nbr_of_philos);
	while (i < info->nbr_of_philos)
	{
		info->philos[i].nbr_of_meals = 0;
		info->philos[i].info = info;
		info->philos[i].id = i;
		info->philos[i].info = info;
		if (i % 2 == 0)
			ft_pair_philo(info, i);
		else
			ft_odd_philo(info, i);
		i++;
	}
	init_threads(info);
}

void	init_threads(t_info *info)
{
	int	i;

	i = 0;
	info->start_time = ft_get_time();
	while (i < info->nbr_of_philos)
	{
		if (i % 2 != 0)
			usleep(1000);
		info->philos[i].last_meal = info->start_time;
		if (pthread_create(&info->philos[i].th, NULL, \
		&ft_routine, &info->philos[i]) != 0)
		{
			ft_print_error("impossible to create a thread");
			return ;
		}
		i++;
	}
}
