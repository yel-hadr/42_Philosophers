/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 05:01:42 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/30 21:39:27 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	do_gen(t_philosophrs *gen, int size, int *ptr)
{
	gen->number_of_philosophers = ptr[0];
	if (!gen->number_of_philosophers)
	{
		printf ("%syou need one or more philosopher o \
start the programe !!%s\n", URED, NOC);
		return (1);
	}
	gen->time_to_die = ptr[1];
	gen->time_to_eat = ptr[2];
	gen->time_to_sleep = ptr[3];
	if (size == 6)
	{
		gen->number_of_to_eat = ptr[4];
		if (gen->number_of_to_eat < 1)
			return (1);
	}
	return (0);
}

int	check_arg(int ac, char **av, t_philosophrs *gen)
{
	int	*ptr;
	int	i;

	i = ac;
	ptr = ft_calloc(sizeof(int), ac - 1);
	if (!ptr)
		return (1);
	while (ac-- > 1)
	{
		if (!check_is_valid(av[ac]))
		{
			printf ("%sOh, Errer wrong input !!%s\n", URED, NOC);
			return (1);
		}
		ptr[ac - 1] = ft_atoi(av[ac]);
	}
	if (do_gen(gen, i, ptr))
		return (1);
	free (ptr);
	return (0);
}
