/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 04:44:51 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/24 13:51:27 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_who_is_died(t_the_philo *info)
{
	long long int time;

	time = real_time(info->starting_time);
	if (time - info->last_meal > info->time_to_die)
	{
		sem_post(info->death);
		return 1;
	}
	return 0;
}

void	ft_sleeping(t_the_philo *philo, int *death)
{
	if (!*death)
	{
		sem_wait(philo->death);
		printf("%lld %d is sleeping\n", ft_get_time() - philo->starting_time, philo->pid);
		sem_post(philo->death);
		ft_sleep(philo->time_to_sleep);
		*death = ft_who_is_died(philo);
	}
}

void	ft_eat(t_the_philo *philo, int *death)
{
	if (!*death)
	{
		*death = ft_who_is_died(philo);
		sem_wait(philo->death);
		philo->last_meal = ft_get_time() - philo->starting_time;
		printf("%lld %d is eating\n", philo->last_meal, philo->pid);
		sem_post(philo->death);
		ft_sleep(philo->time_to_eat);
		sem_post(philo->forks);
		sem_post(philo->forks);
	}
}

void	ft_thinking(t_the_philo *info, int *death)
{
	if (!*death)
	{
		*death = ft_who_is_died(info);
		sem_wait(info->death);
		printf("%lld %d is thinking\n", ft_get_time() - info->starting_time, info->pid);
		sem_post(info->death);
	}
}

void	ft_teken_the_fork(sem_t *sem, t_the_philo *info, int *death)
{
	if (!*death)
	{
		*death = ft_who_is_died(info);
		sem_wait(sem);
		sem_wait(info->death);
		printf("%lld %d has taken a fork\n", ft_get_time() - info->starting_time, info->pid);
		sem_post(info->death);
		if (info->number_of_philosophers == 1)
		{
			ft_sleep(info->time_to_die);
			exit(1);
		}
		sem_wait(sem);
		sem_wait(info->death);
		printf("%lld %d has taken a fork\n", ft_get_time() - info->starting_time, info->pid);
		sem_post(info->death);
	}
}