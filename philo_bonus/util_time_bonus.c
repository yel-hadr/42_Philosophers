/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_time_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 01:57:46 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/30 21:40:06 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long int	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday (&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long long int	real_time(long long int starting)
{
	return (ft_get_time() - starting);
}

int	ft_sleep(long long int time)
{
	long long int	sleep;

	sleep = 0;
	time += ft_get_time();
	while (sleep < time)
	{
		usleep(200);
		sleep = ft_get_time();
	}
	return (0);
}
