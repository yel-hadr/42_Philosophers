/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:22:45 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/24 10:56:01 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_death(t_philosophrs *philo)
{
	int status;
	int pid;
	int j;

	(void) philo;
	status = 0;
	j = philo->number_of_philosophers;
	while (j)
	{
		pid = waitpid(-1, &status, 0);
		if (status)
		{
			int i;
			i = philo->number_of_philosophers;
			while (i--)
				kill (philo->pid[i], SIGINT);
			printf ("%lld %d died\n", real_time(philo->starting_time), pid);
			break;	
		}
		else if(!status)
			j--;
	}
	return (0);
}