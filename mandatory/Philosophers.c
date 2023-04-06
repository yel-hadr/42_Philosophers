/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 21:35:09 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/05 05:23:17 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

t_philosophrs	ft_join_thread(t_philosophrs philosophers)
{
	int i;
	i = philosophers.number_of_philosophers;
	while (i--)
		pthread_join(philosophers.philo[i], NULL);
	return (philosophers);
}

int main(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		printf("Oh, Errer");
		return (1);
	}
	t_philosophrs gen;
	check_arg(ac , av, &gen);
	gen = ft_init_the_fork(gen);
	gen = ft_init_the_thread(gen);
	gen = ft_join_thread(gen);
}