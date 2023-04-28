/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_the_fork.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:26:10 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/28 17:11:07 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philosophrs	*ft_init_the_fork(t_philosophrs *philosophrs)
{
	int	i;

	i = philosophrs->number_of_philosophers;
	philosophrs->mutex = ft_calloc(sizeof(pthread_mutex_t), i);
	philosophrs->stop = ft_calloc(sizeof(pthread_mutex_t), i);
	if (!philosophrs->mutex || !philosophrs->stop)
		ft_exit(philosophrs);
	while (i--)
	{
		pthread_mutex_init(&philosophrs->mutex[i], NULL);
		pthread_mutex_init(&philosophrs->stop[i], NULL);
	}
	return (philosophrs);
}
