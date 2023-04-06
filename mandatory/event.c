/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 02:19:44 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/06 02:30:12 by yel-hadr         ###   ########.fr       */
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
			pthread_mutex_lock(info->l_fork.mutex);
			pthread_mutex_lock(info->r_fork.mutex);
		}
		else 
		{
			pthread_mutex_lock(info->r_fork.mutex);
			pthread_mutex_lock(info->l_fork.mutex);
		}
		printf("%d I'm eating\n", info->id);
		sleep(10);
		pthread_mutex_unlock(info->r_fork.mutex);
		pthread_mutex_unlock(info->l_fork.mutex);
		printf("hi, sleep %d\n", info->id);
		sleep(10);
		printf("%d id thinking\n", info->id);
	}
	return (NULL);
}