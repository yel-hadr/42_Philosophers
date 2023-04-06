/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 02:19:44 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/06 21:40:42 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"



void	*ft_philosophers(void *arg)
{
	t_the_philo *info;
	info = arg;
	info->starting_time = ft_get_time();
	if (!info->id ||info->id % 2 == 0)
	{
		printf("%lld %d is thinking\n", real_time(info->starting_time),info->id);
		usleep(500);
	}
	while (1)
	{
		if (info->id % 2 == 1)
		{
			ft_teken_the_fork(info->id, info->l_fork.mutex, info->starting_time);
			ft_teken_the_fork(info->id, info->r_fork.mutex, info->starting_time);
		}
		else
		{
			ft_teken_the_fork(info->id, info->l_fork.mutex, info->starting_time);
			ft_teken_the_fork(info->id, info->r_fork.mutex, info->starting_time);
		}
		ft_eat(info->id, info);
		ft_sleeping(info->id, info);
		ft_thinking(info->id, info->starting_time);
	}
	return (NULL);
}