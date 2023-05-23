/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:12:58 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/05/11 21:17:31 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_args(int argc, char **argv)
{
	int	i;
	int	j;

	if (!(argc == 5 || argc == 6))
		return (ft_print_error("not right number of arguments"));
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j++]) == 0)
				return (ft_print_error("args must be just positive integers"));
		}
		if (argv[1][0] == '0')
			return (ft_print_error("number of philosophers must be above 0"));
		if (argc == 6)
		{
			if (argv[5][0] == '0')
				return (ft_print_error \
				("times each philosopher must eat must be above 0"));
		}
		i++;
	}
	return (1);
}
