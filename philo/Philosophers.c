/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 21:35:09 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/27 19:42:14 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int main(int ac, char **av)
{
	t_philosophrs *gen;
	
	if (ac != 5 && ac != 6)
	{
		printf("Oh, Errer");
		return (1);
	}
	gen = ft_calloc(sizeof(t_philosophrs), 1);
	if (!gen)
		return (1);
	gen->number_of_to_eat = -1;
	if (check_arg(ac , av, gen))
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