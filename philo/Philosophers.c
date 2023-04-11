/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 21:35:09 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/11 05:56:08 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	ft_is_die(int *death, t_philosophrs philo)
{
	int i;
	
	i = philo.number_of_philosophers;
	while(i--)
	{
		if (death[i])
		{
			return (i);
		}
	}
	return (0);
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
			int j = philo.number_of_philosophers;
			while (j--)
			{
				pthread_mutex_lock(&philo.stop[j]);
				pthread_detach(philo.philo[i]);
			}
			printf("%lld %d died\n",philo.info[i].last_meal, philo.info[i].id);
			usleep(10000);
			exit(1);
		}
	}
	return (philo);
}

int main(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		printf("Oh, Errer");
		return (1);
	}
	t_philosophrs gen;
	gen.number_of_to_eat = -1;
	check_arg(ac , av, &gen);
	gen = ft_init_the_fork(gen);
	gen = ft_philo_info(gen);
	gen = start_thread(gen);
	ft_check_death(gen);
}