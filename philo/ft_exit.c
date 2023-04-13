/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 04:50:09 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/13 02:41:43 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

t_philosophrs	ft_exit(t_philosophrs philo, int i)
{
	if (philo.mutex)
		free(philo.mutex);
	if (philo.stop)
		free(philo.stop);
	if (philo.philo)
		free (philo.philo);
	if (philo.die)
		free (philo.die);
	if (philo.info)
		free(philo.info);
	if (i)
		exit(1);
	return (philo);
}