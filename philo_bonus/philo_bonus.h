/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 21:35:11 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/16 22:36:52 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H

# define PHILO_BONUS_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <semaphore.h>
#include <sys/time.h>

typedef struct s_fork
{
	pthread_mutex_t *mutex;
}	t_fork;


typedef struct s_the_philo
{
	int id;
	t_fork r_fork;
	t_fork l_fork;
	int *die;
	pthread_mutex_t *stop;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int number_of_to_eat;
	long long int	last_meal;
	long long int	starting_time;
}	t_the_philo;

typedef struct s_philosophrs
{
	pthread_t *philo;
	pthread_mutex_t *mutex;
	int *die;
	pthread_mutex_t *stop;
	int number_of_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int number_of_to_eat;
	t_the_philo *info;
}	t_philosophrs;

#endif
