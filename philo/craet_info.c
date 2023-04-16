/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   craet_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:35:06 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/16 01:57:36 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

t_the_philo do_the_philo(t_philosophrs philosoohrs, int i)
{
	t_the_philo the_philo;
	the_philo.id = i + 1;
	philosoohrs.die[i] = 0;
	the_philo.die = &philosoohrs.die[i];
	the_philo.stop = &philosoohrs.stop[i];
	the_philo.time_to_die = philosoohrs.time_to_die;
	the_philo.time_to_eat = philosoohrs.time_to_eat;
	the_philo.time_to_sleep = philosoohrs.time_to_sleep;
	the_philo.number_of_to_eat = philosoohrs.number_of_to_eat;
	the_philo.r_fork.mutex = &philosoohrs.mutex[i];
	if (!i)
		the_philo.l_fork.mutex = &philosoohrs.mutex[philosoohrs.number_of_philosophers - 1];
	else
		the_philo.l_fork.mutex = &philosoohrs.mutex[i - 1];
	the_philo.starting_time = ft_get_time();
	return (the_philo);
}

t_philosophrs	ft_philo_info(t_philosophrs philo)
{
	int i;
	i = philo.number_of_philosophers;
	philo.philo = ft_calloc(sizeof(pthread_t), i);
	philo.die = ft_calloc(sizeof(int), i);
	philo.info = ft_calloc(sizeof(t_the_philo), i);
	if (!philo.die || !philo.philo || !philo.info)
		ft_exit(philo, 1);
	while (i--)
		philo.info[i] = do_the_philo(philo, i);
	return philo;
}
