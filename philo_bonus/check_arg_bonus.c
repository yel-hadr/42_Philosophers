/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 05:01:42 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/30 21:41:57 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_fill_struct(t_philosophrs *gen, int size, int *ptr)
{
	gen->number_of_philosophers = ptr[0];
	if (gen->number_of_philosophers < 1)
	{
		printf ("%sError: Uh oh, it looks like you need one or more philosophers \
to start the program. Please add a philosopher and try again.%s\n", URED, NOC);
		return (1);
	}
	gen->time_to_die = ptr[1];
	gen->time_to_eat = ptr[2];
	gen->time_to_sleep = ptr[3];
	gen->number_of_to_eat = -1;
	if (size == 6)
	{
		gen->number_of_to_eat = ptr[4];
		if (!gen->number_of_to_eat)
			exit(0);
	}
	return (0);
}

void	check_arg(int ac, char **av, t_philosophrs *gen)
{
	int	*ptr;
	int	i;

	i = ac;
	ptr = ft_calloc(sizeof(int), ac - 1);
	if (!ptr)
		exit(1);
	while (ac-- > 1)
	{
		if (!check_is_valid(av[ac]))
		{
			printf("%sError: Oops, wrong input! Please try again.%s\n", \
			URED, NOC);
			exit(1);
		}
		ptr[ac - 1] = (int)ft_atoi(av[ac]);
	}
	if (ft_fill_struct(gen, i, ptr))
		exit(1);
	free (ptr);
}
