/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:59:58 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/05/11 21:17:25 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_isnegative(char c)
{
	if (c == '-')
		return (1);
	return (0);
}

int	ft_ispositive(char c)
{
	if (c == '+')
		return (1);
	return (0);
}

int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	r;
	int	i;
	int	signal;

	r = 0;
	i = 0;
	signal = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (ft_isnegative(nptr[i]) || ft_ispositive(nptr[i]))
	{
		if (ft_isnegative(nptr[i++]))
		signal = -1;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		r *= 10;
		r += nptr[i] - '0';
		i++;
	}
	return (r * signal);
}
