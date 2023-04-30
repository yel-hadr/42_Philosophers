/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:22:45 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/30 19:56:34 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_killer(t_philosophrs *philo, int pid)
{
	int	i;
	int	j;

	i = philo->number_of_philosophers;
	while (i--)
	{
		kill (philo->pid[i], SIGINT);
		if (philo->pid[i] == pid)
			j = i;
	}
	return (j);
}

int	check_death(t_philosophrs *philo)
{
	int	status;
	int	pid;
	int	j;

	(void) philo;
	status = 0;
	j = philo->number_of_philosophers;
	while (j)
	{
		pid = waitpid(-1, &status, 0);
		if (status && pid > 0)
		{
			pid = ft_killer(philo, pid);
			printf ("%lld %d died\n", real_time(philo->starting_time), pid + 1);
			break ;
		}
		else if (!status && pid > 0)
			j--;
	}
	return (0);
}
