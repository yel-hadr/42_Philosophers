/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 23:00:58 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/16 21:56:10 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
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
	
	return (0);
}
