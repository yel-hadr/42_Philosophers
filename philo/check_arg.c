/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 05:01:42 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/25 16:44:11 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	check_arg(int ac , char **av, t_philosophrs *gen)
{
	int *ptr;
	int i;

	i = ac;
	ptr = ft_calloc(sizeof(int), ac - 1);
	if (!ptr)
		return 1;
	while (ac-- > 1)
	{
		if (!check_is_valid(av[ac]))
		{
			printf("Oh, Errer wrong input !!\n");
			return 1;
		}
		ptr[ac - 1] = ft_atoi(av[ac]);
	}
	gen->number_of_philosophers = ptr[0];
	if (gen->number_of_philosophers < 1)
	{
		printf ("you need more then one philosopher o start the programme !!");
		return 1;
	}
	gen->time_to_die = ptr[1];
	gen->time_to_eat = ptr[2];
	gen->time_to_sleep = ptr[3];
	if (i == 6)
		gen->number_of_to_eat = ptr[4];
	free(ptr);
	return (0);
}