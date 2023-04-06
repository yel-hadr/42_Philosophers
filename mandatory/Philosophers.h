/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 21:35:11 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/06 02:24:50 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOOHERS_H

# define PHILOSOOHERS_H

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

typedef struct s_fork
{
	int *fork;
	pthread_mutex_t *mutex;
}	t_fork;

typedef struct s_philosophrs
{
	pthread_t *philo;
	pthread_mutex_t *mutex;
	int *tabel;
	int number_of_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
}	t_philosophrs;

typedef struct s_the_philo
{
	int id;
	t_fork r_fork;
	t_fork l_fork;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
}	t_the_philo;

void			*ft_calloc(size_t count, size_t size);
void			check_arg(int ac , char **av, t_philosophrs *gen);
t_philosophrs	ft_init_the_fork(t_philosophrs philosophrs);
t_philosophrs	ft_init_the_thread(t_philosophrs philosophrs);
void	*ft_philosophers(void *arg);

#endif