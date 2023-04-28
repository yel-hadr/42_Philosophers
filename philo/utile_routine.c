/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 04:44:51 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/28 18:56:50 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_who_is_died(t_the_philo *info)
{
	long long int	time;

	if (*info->die == 2)
		return (0);
	time = real_time(info->starting_time);
	if (time - info->last_meal > info->time_to_die)
	{
		info->last_meal = real_time(info->starting_time);
		*info->die = 1;
		return (1);
	}
	return (0);
}

void	ft_sleeping(int id, t_the_philo *philo)
{
	if (!*philo->die)
	{
		pthread_mutex_lock(philo->stop);
		printf("%lld %d is sleeping\n", ft_get_time() - \
				philo->starting_time, id);
		pthread_mutex_unlock(philo->stop);
		ft_sleep(philo->time_to_sleep);
	}
}

void	ft_eat(int id, t_the_philo *philo)
{
	if (!*philo->die)
	{
		pthread_mutex_lock(philo->stop);
		philo->last_meal = ft_get_time() - philo->starting_time;
		printf("%lld %d is eating\n", philo->last_meal, id);
		pthread_mutex_unlock(philo->stop);
		ft_sleep(philo->time_to_eat);
		pthread_mutex_unlock(philo->r_fork.mutex);
		pthread_mutex_unlock(philo->l_fork.mutex);
	}
}

void	ft_thinking(int id, t_the_philo *info)
{
	if (!*info->die)
	{
		pthread_mutex_lock(info->stop);
		printf("%lld %d is thinking\n", ft_get_time() - info->starting_time, id);
		pthread_mutex_unlock(info->stop);
	}
}

void	ft_teken_the_fork(int id, pthread_mutex_t *mutex, t_the_philo *info)
{
	if (mutex)
		pthread_mutex_lock(mutex);
	if (!*info->die)
	{
		pthread_mutex_lock(info->stop);
		printf("%lld %d has taken a fork\n", \
			ft_get_time() - info->starting_time, id);
		pthread_mutex_unlock(info->stop);
	}
}
