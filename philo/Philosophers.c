/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 21:35:09 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/30 21:41:44 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philosophrs	*gen;

	if (ac != 5 && ac != 6)
	{
		printf("%sErrer 404 : Read the subject PLS%s\n", URED, NOC);
		return (1);
	}
	gen = ft_calloc(sizeof(t_philosophrs), 1);
	if (!gen)
		return (1);
	gen->number_of_to_eat = -1;
	if (check_arg(ac, av, gen))
	{
		free (gen);
		return (1);
	}
	ft_init_the_fork(gen);
	ft_philo_info(gen);
	start_thread(gen);
	ft_check_death(*gen);
	ft_exit(gen);
	return (0);
}
