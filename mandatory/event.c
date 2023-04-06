/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 02:19:44 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/06 04:45:15 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"



void	*ft_philosophers(void *arg)
{
	t_the_philo *info;
	info = arg;
	if (!info->id ||info->id % 2 == 0)
	{
		printf("%d id thinking\n", info->id);
		usleep(20);
	}
	while (1)
	{
		if (info->id % 2 == 0)
		{
			ft_teken_the_fork(info->id, info->l_fork.mutex);
			ft_teken_the_fork(info->id, info->r_fork.mutex);
		}
		else
		{
			ft_teken_the_fork(info->id, info->l_fork.mutex);
			ft_teken_the_fork(info->id, info->r_fork.mutex);
		}
		ft_eat(info->id, info);
		ft_sleeping(info->id, info);
		ft_thinking(info->id);
	}
	return (NULL);
}