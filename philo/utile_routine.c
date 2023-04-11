/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 04:44:51 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/11 05:54:36 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	ft_who_is_died(long long int time, t_the_philo *info)
{
	if (time - info->last_meal > info->time_to_die)
	{
		info->last_meal = time;
		*info->die = 1;
		return 1; 
	}
	return 0;
}

void	ft_sleeping(int id, t_the_philo *philo)
{
	long long int time;
	time = real_time(philo->starting_time);
	if (!ft_who_is_died(time, philo) && !*philo->die)
	{
		pthread_mutex_lock(philo->stop);
		printf("%lld %d is sleeping\n", time, id);
		pthread_mutex_unlock(philo->stop);
		ft_sleep(philo->time_to_sleep, philo->starting_time);
	}
}

void	ft_eat(int id, t_the_philo *philo)
{
	long long int time;
	time = real_time(philo->starting_time);
	if (!ft_who_is_died(time, philo) && !*philo->die)
	{
		pthread_mutex_lock(philo->stop);
		time = real_time(philo->starting_time);
		philo->last_meal = time;
		printf("%lld %d is eating\n", time ,id);
		pthread_mutex_unlock(philo->stop);
		ft_sleep(philo->time_to_eat , philo->starting_time);
		pthread_mutex_unlock(philo->r_fork.mutex);
		pthread_mutex_unlock(philo->l_fork.mutex);
	}
}

void	ft_thinking(int id, t_the_philo *info)
{
	long long int time;
	time = real_time(info->starting_time);
	if (!ft_who_is_died(time, info) && !*info->die)
	{
		pthread_mutex_lock(info->stop);
		printf("%lld %d is thinking\n", time,id);
		pthread_mutex_unlock(info->stop);
	}
}

void	ft_teken_the_fork(int id, pthread_mutex_t *mutex, t_the_philo *info)
{
	long long int time;
	pthread_mutex_lock(mutex);
	time = real_time(info->starting_time);
	if (!ft_who_is_died(time, info) && !*info->die)
	{
		pthread_mutex_lock(info->stop);
		printf("%lld %d has taken a fork\n", time,id);
		pthread_mutex_unlock(info->stop);
	}
}