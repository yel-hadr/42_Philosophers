/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 02:03:17 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/07 02:55:59 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

t_philosophrs	ft_init_the_fork(t_philosophrs philosophrs)
{
	int i;
	i = philosophrs.number_of_philosophers;
	philosophrs.tabel = ft_calloc(sizeof(int), i);
	philosophrs.mutex = ft_calloc(sizeof(pthread_mutex_t), i);
	while (i--)
	{
		pthread_mutex_init(&philosophrs.mutex[i], NULL);
		philosophrs.tabel[i] = 1;
	}
	return (philosophrs);
}

t_the_philo *do_the_philo(t_the_philo *the_philo, t_philosophrs philosoohrs, int i)
{
	the_philo = ft_calloc(sizeof(t_the_philo), 1);
	the_philo->id = i;
	the_philo->time_to_die = philosoohrs.time_to_die;
	the_philo->time_to_eat = philosoohrs.time_to_eat;
	the_philo->time_to_sleep = philosoohrs.time_to_sleep;
	the_philo->r_fork.mutex = &philosoohrs.mutex[i];
	the_philo->r_fork.fork = &philosoohrs.tabel[i];
	if (!i)
	{
		the_philo->l_fork.mutex = &philosoohrs.mutex[philosoohrs.number_of_philosophers - 1];
		the_philo->l_fork.fork = &philosoohrs.tabel[philosoohrs.number_of_philosophers - 1];
	}
	else
	{
		the_philo->l_fork.mutex = &philosoohrs.mutex[i - 1];
		the_philo->l_fork.fork = &philosoohrs.tabel[i - 1];
	}
	return (the_philo);
}


t_philosophrs	ft_init_the_thread(t_philosophrs philosophrs)
{
	int i;
	i = philosophrs.number_of_philosophers;
	philosophrs.philo = ft_calloc(sizeof(pthread_t), i);
	while (i--)
	{
		t_the_philo *the_philo;
		the_philo = NULL;
		the_philo = do_the_philo(the_philo, philosophrs, i);
		pthread_create(&philosophrs.philo[i], NULL, &ft_philosophers, the_philo);
	}
	
	return (philosophrs);
}
