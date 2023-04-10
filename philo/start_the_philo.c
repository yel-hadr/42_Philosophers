/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_the_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 02:25:10 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/10 05:14:19 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

static int is_died(long long int last_meal, long long int starting, long long int time_to_die)
{
	if (real_time(starting) - last_meal > time_to_die)
		return (1);
	return (0);
}

void	*ft_routine(void *arg)
{
	t_the_philo	*info;
	int i = 0;

	info = (t_the_philo *)arg;
	info->starting_time = ft_get_time();
	if (info->id % 2 == 1)
	{
		ft_thinking(info->id, info->starting_time, info->stop);
		usleep(200);
	}
	while (i != info->number_of_to_eat)
	{
		if (info->id % 2 == 0)
		{
			ft_teken_the_fork(info->id, info->r_fork.mutex, info->starting_time, info->stop);
			ft_teken_the_fork(info->id, info->l_fork.mutex, info->starting_time, info->stop);
		}
		else
		{
			ft_teken_the_fork(info->id, info->l_fork.mutex, info->starting_time, info->stop);
			ft_teken_the_fork(info->id, info->r_fork.mutex, info->starting_time, info->stop);
		}
		if (is_died(info->last_meal, info->starting_time, info->time_to_die))
		{
			*info->die = 1;
		}
		ft_eat(info->id, info);
		ft_sleeping(info->id, info);
		ft_thinking(info->id, info->starting_time, info->stop);
		i++;
	}
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
