/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 01:57:46 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/11 05:23:16 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

long long int	ft_get_time(void)
{
	struct timeval     time;
    gettimeofday(&time, NULL);
	return (time.tv_sec * 1000) + (time.tv_usec / 1000);
}

long long int	real_time(long long int starting)
{
	return (ft_get_time() - starting);
}

void	ft_sleep(long long int time, long long int starting)
{
	long long int sleep = 0;
	time += real_time(starting);
	while (sleep < time)
	{
		usleep(500);
		sleep = real_time(starting);
	}
}
