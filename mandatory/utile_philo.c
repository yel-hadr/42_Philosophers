/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 04:44:51 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/06 04:45:19 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

void	ft_sleeping(int id, t_the_philo *philo)
{
	(void)philo;
	printf("%d is sleeping\n", id);
	sleep(1);
}

void	ft_eat(int id, t_the_philo *philo)
{
	printf("%d is eating\n", id);
	sleep(1);
	pthread_mutex_unlock(philo->r_fork.mutex);
	pthread_mutex_unlock(philo->l_fork.mutex);
}

void	ft_thinking(int id)
{
	printf("%d is thinking\n", id);
}

void	ft_teken_the_fork(int id, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	printf("%d has taken a fork\n", id);
}