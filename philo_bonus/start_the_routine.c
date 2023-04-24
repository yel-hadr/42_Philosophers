/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_the_routine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 02:25:10 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/24 11:26:49 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_routine(t_the_philo *info)
{
	int i = 0;
	int death = 0;
	
	info->last_meal = real_time(info->starting_time);
	while (i != info->number_of_to_eat && !death)
	{
		ft_thinking(info, &death);
		ft_teken_the_fork(info->forks, info, &death);
		ft_eat(info, &death);
		ft_sleeping(info, &death);
		i++;
	}
	return (death);
}
