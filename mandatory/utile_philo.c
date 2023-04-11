/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 04:44:51 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/07 02:51:41 by yel-hadr         ###   ########.fr       */
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

void	ft_sleeping(int id, t_the_philo *philo)
{
	long long int time;
	time = real_time(philo->starting_time);
	printf("%lld %d is sleeping\n", time, id);
	ft_sleep(philo->time_to_sleep, philo->starting_time);
}

void	ft_eat(int id, t_the_philo *philo)
{
	long long int time;
	time = real_time(philo->starting_time);
	printf("%lld %d is eating\n", time ,id);
	ft_sleep(philo->time_to_eat , philo->starting_time);
	pthread_mutex_unlock(philo->r_fork.mutex);
	pthread_mutex_unlock(philo->l_fork.mutex);
}

void	ft_thinking(int id, long long int starting)
{
	long long int time;
	time = real_time(starting);
	printf("%lld %d is thinking\n", time,id);
}

void	ft_teken_the_fork(int id, pthread_mutex_t *mutex, long long int starting)
{
	long long int time;
	pthread_mutex_lock(mutex);
	time = real_time(starting);
	printf("%lld %d has taken a fork\n", time,id);
}