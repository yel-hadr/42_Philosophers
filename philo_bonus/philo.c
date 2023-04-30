/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 23:00:58 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/30 20:12:37 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_the_philo		the_philo;
	t_philosophrs	*gen;
	int				pid;

	if (ac != 5 && ac != 6)
	{
		printf("%sErrer 404 : Read the subject PLS%s\n", URED, NOC);
		return (1);
	}
	gen = ft_calloc(sizeof(t_philosophrs), 1);
	if (!gen)
		return (1);
	check_arg(ac, av, gen);
	pid = ft_creat_the_philo(gen, &the_philo);
	if (!pid)
		pid = ft_routine(&the_philo);
	else
		pid = check_death(gen);
	return (pid);
}
