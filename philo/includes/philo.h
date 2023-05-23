/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:04:53 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/05/11 21:17:07 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>

# define YELLOW	"\x1B[33m"
# define RED   "\x1B[38;2;255;102;102m"
# define RESET "\x1B[0m"
# define CIANO "\x1B[96m" 
# define PINK   "\x1B[94m"   
# define BG "\033[41m"

typedef struct s_philo
{
	int					id;
	int					nbr_of_meals;
	long long			last_meal;
	struct s_info		*info;
	pthread_t			th;
	pthread_mutex_t		*first_fork;
	pthread_mutex_t		*second_fork;
}				t_philo;

typedef struct s_info
{
	long long			start_time;
	int					nbr_of_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					times_each_philo_must_eat;
	int					any_philo_is_dead;
	int					nbr_of_dead_philo;
	int					meals_complete;
	int					print_lock;
	pthread_mutex_t		can_die;
	pthread_mutex_t		print_lock_mutex;
	pthread_mutex_t		any_philo_is_dead_mutex;
	pthread_mutex_t		meals_complete_mutex;
	pthread_mutex_t		last_meal_mutex;
	pthread_mutex_t		*forks;
	pthread_t			checker;
	struct s_philo		*philos;
}						t_info;

// ==== ft_actions ====
void				ft_take_forks(t_philo *philo);
void				ft_eat(t_philo *philo);
void				ft_think(t_philo *philo);
void				ft_sleep(t_philo *philo);

// ==== ft_ atoi ====
int					ft_atoi(const char *nptr);

// ==== ft_can_continue ====
int					ft_can_continue(t_info *info);
int					ft_dead_philos(t_philo *philo);

// ==== ft_check_args ====
int					ft_check_args(int argc, char **argv);

// ==== ft_destroy_all ==== 
void				ft_destroy_all(t_info *info);

// ==== ft_get_time ====
long long			ft_get_time(void);

// ==== ft_init_structs ====
void				ft_init_structs(t_info *info, int argc, char **argv);
void				ft_init_info_mutexes(t_info *info);
void				ft_init_info(t_info *info, int argc, char **argv);
pthread_mutex_t		*ft_init_forks(t_info *info);
void				ft_init_philosophers(t_info *info);
void				init_threads(t_info *info);

// ==== ft_print_msg ====
void				ft_print_msg(char *str, t_philo *philo, char *color);
int					ft_print_error(char *str);

// ==== ft_routine ====
void				*ft_routine(void *data);
void				*ft_just_one_philo(t_philo *philo);

// ==== utils ====
int					ft_isdigit(int c);
void				ft_check_deaths(t_info *info);
void				ft_pair_philo(t_info *info, int i);
void				ft_odd_philo(t_info *info, int i);
void				ft_init_info_mutexes(t_info *info);

#endif