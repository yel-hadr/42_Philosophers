/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 21:35:09 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/13 01:45:51 by yel-hadr         ###   ########.fr       */
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
		if (death[i] == 1)
			return (i);
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
		usleep(1000);
		i = ft_is_die(philo.die, philo);
		if (i)
		{
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
	t_philosophrs *gen;
	
	gen = ft_calloc(sizeof(t_philosophrs), 1);
	if (!gen)
		return (1);
	gen->number_of_to_eat = -1;
	check_arg(ac , av, gen);
	*gen = ft_init_the_fork(*gen);
	*gen = ft_philo_info(*gen);
	*gen = start_thread(*gen);
	ft_check_death(*gen);
	free (gen);
	return (0);
}