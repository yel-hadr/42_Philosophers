/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_the_routine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 02:25:10 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/30 20:14:21 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_checker_routine(void *arg)
{
	t_the_philo	*info;

	info = (t_the_philo *)arg;
	while (1)
	{
		if (ft_who_is_died(info))
			exit(1);
		usleep (200);
	}
	return (NULL);
}

int	ft_routine(t_the_philo *info)
{
	pthread_t	checker;
	int			i;

	i = 0;
	info->last_meal = real_time(info->starting_time);
	pthread_create(&checker, NULL, ft_checker_routine, info);
	while (i != info->number_of_to_eat)
	{
		ft_thinking(info);
		ft_teken_the_fork(info->forks, info);
		ft_eat(info);
		ft_sleeping(info);
		i++;
	}
	exit(0);
	return (0);
}
