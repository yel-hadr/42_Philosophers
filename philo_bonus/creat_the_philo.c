/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_the_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:41:18 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/30 20:03:46 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_the_philo	ft_get_info(t_philosophrs philosoohrs, int id)
{
	t_the_philo	the_philo;

	the_philo.pid = id + 1;
	the_philo.starting_time = philosoohrs.starting_time;
	the_philo.time_to_die = philosoohrs.time_to_die;
	the_philo.time_to_eat = philosoohrs.time_to_eat;
	the_philo.number_of_philosophers = philosoohrs.number_of_philosophers;
	the_philo.time_to_sleep = philosoohrs.time_to_sleep;
	the_philo.number_of_to_eat = philosoohrs.number_of_to_eat;
	the_philo.forks = sem_open("/fork", 0);
	the_philo.death = sem_open("/death", 0);
	return (the_philo);
}

void	fill_t_philosophrs(t_philosophrs *philo, int pid, int i)
{
	sem_unlink("/fork");
	sem_unlink("/death");
	philo->pid = ft_calloc(sizeof(int), philo->number_of_philosophers);
	philo->forks = sem_open ("/fork", O_CREAT, 0644, \
	philo->number_of_philosophers);
	philo->death = sem_open ("/death", O_CREAT, 0644, 3);
	if (philo->forks == SEM_FAILED || philo->death == SEM_FAILED \
			|| !philo->pid)
		exit(1);
	philo->pid[i] = pid;
}

int	ft_creat_the_philo(t_philosophrs *philo, t_the_philo *the_philo)
{
	int	pid;
	int	i;

	i = philo->number_of_philosophers - 1;
	philo->starting_time = ft_get_time();
	pid = fork ();
	if (pid)
		fill_t_philosophrs(philo, pid, i);
	while (pid && i)
	{
		i--;
		pid = fork();
		if (pid)
			philo->pid[i] = pid;
	}
	if (!pid)
		*the_philo = ft_get_info(*philo, i);
	return (pid);
}
