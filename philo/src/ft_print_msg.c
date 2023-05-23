/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:07:03 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/05/11 21:17:48 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_print_msg(char *str, t_philo *philo, char *color)
{
	pthread_mutex_lock(&philo->info->print_lock_mutex);
	if (philo->info->print_lock == -1)
		printf("%s""%lld %d %s\n", color, \
		ft_get_time() - philo->info->start_time, philo->id, str);
	pthread_mutex_unlock(&philo->info->print_lock_mutex);
}

int	ft_print_error(char *str)
{
	printf(RESET BG "  Error: %s  \n" RESET, str);
	return (-1);
}
