/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_the_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 02:25:10 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/29 22:57:02 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	do_teking_the_forks(t_the_philo	*info)
{
	if (info->id % 2 == 1)
	{
		ft_teken_the_fork(info->id, info->r_fork.mutex, info);
		ft_teken_the_fork(info->id, info->l_fork.mutex, info);
	}
	else
	{
		ft_teken_the_fork(info->id, info->l_fork.mutex, info);
		ft_teken_the_fork(info->id, info->r_fork.mutex, info);
	}
}

void	*ft_routine(void *arg)
{
	t_the_philo	*info;

	info = (t_the_philo *)arg;
	info->last_meal = real_time(info->starting_time);
	if (info->id % 2 == 1)
	{
		ft_thinking(info->id, info);
		usleep(100);
	}
	while (1)
	{
		if (*info->die)
			break ;
		do_teking_the_forks(info);
		ft_eat(info->id, info);
		info->number_of_to_eat--;
		ft_sleeping(info->id, info);
		ft_thinking(info->id, info);
	}
	return (NULL);
}

t_philosophrs	*start_thread(t_philosophrs *philo)
{
	int	i;

	if (!philo)
		return (NULL);
	i = philo->number_of_philosophers;
	while (i--)
		pthread_create(&philo->philo[i], NULL, &ft_routine, &philo->info[i]);
	return (philo);
}
