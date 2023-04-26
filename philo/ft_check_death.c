/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_death.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:50:40 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/26 21:51:03 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	ft_is_die(int *death, t_philosophrs philo)
{
	int i;
	int die;
	
	i = philo.number_of_philosophers;
	die = 2;
	while(i--)
	{
		if (ft_who_is_died(&philo.info[i]) == 1)
			return (i + 1);
		else if (death[i] != 2)
			die = 0;
	}
	return (die);
}

t_philosophrs ft_check_death(t_philosophrs philo)
{
	int i;

	i = 0;
	while (!i)
	{
		i = ft_is_die(philo.die, philo);
		if (i)
		{
			i--;
			int j = philo.number_of_philosophers;
			while (j--)
			{
				pthread_mutex_lock(&philo.stop[j]);
				pthread_detach(philo.philo[j]);
				pthread_mutex_destroy(&philo.mutex[j]);
				pthread_mutex_destroy(&philo.stop[j]);
			}
			if (*philo.info[i].die == 1)
				printf("%lld %d died\n",philo.info[i].last_meal, philo.info[i].id);
			break;
		}
		usleep(500);
	}
	return (philo);
}
