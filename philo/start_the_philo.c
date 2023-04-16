/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_the_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 02:25:10 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/16 01:57:20 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

void	*ft_routine(void *arg)
{
	t_the_philo	*info;
	int i = 0;

	info = (t_the_philo *)arg;
	if (info->id % 2 == 1)
	{
		ft_thinking(info->id, info);
		usleep(100);
	}
	while (i != info->number_of_to_eat)
	{
		if (info->id % 2 == 1)
		{
			ft_teken_the_fork(info->id, info->r_fork.mutex, info);
			ft_teken_the_fork(info->id, info->l_fork.mutex, info);
		}
		else{
			ft_teken_the_fork(info->id, info->l_fork.mutex, info);
			ft_teken_the_fork(info->id, info->r_fork.mutex, info);
		}
		ft_eat(info->id, info);
		ft_sleeping(info->id, info);
		ft_thinking(info->id, info);
		i++;
	}
	if (!*info->die)
		*info->die = 2;
	return (NULL);
}

t_philosophrs	start_thread(t_philosophrs philo)
{
	int i;
	
	i = philo.number_of_philosophers;
	while(i--)
		pthread_create(&philo.philo[i], NULL, &ft_routine, &philo.info[i]);
	return (philo);
}
