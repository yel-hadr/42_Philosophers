/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 21:35:11 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/30 20:11:19 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H

# define PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <fcntl.h>
# include <sys/stat.h> 
# include <semaphore.h>
# include <pthread.h>
# include <signal.h>
# include <sys/wait.h>
# include <limits.h>

# define URED "\e[4;31m"
# define NOC "\e[0m"

typedef struct s_the_philo
{
	long long int	last_meal;
	long long int	starting_time;
	sem_t			*forks;
	sem_t			*death;
	int				pid;
	int				number_of_to_eat;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
}	t_the_philo;

typedef struct s_philosophrs
{
	long long int	starting_time;
	sem_t			*forks;
	sem_t			*death;
	int				*pid;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_to_eat;
	int				number_of_philosophers;
}	t_philosophrs;

int				check_is_valid(char *str);
long long int	ft_atoi(const char *str);
long long int	ft_get_time(void);
long long int	real_time(long long int starting);
void			*ft_calloc(size_t count, size_t size);
void			check_arg(int ac, char **av, t_philosophrs *gen);
int				ft_creat_the_philo(t_philosophrs *philo, \
		t_the_philo *the_philo);
long long int	ft_get_time(void);
long long int	real_time(long long int starting);
int				ft_sleep(long long int time);
int				ft_routine(t_the_philo *info);
int				ft_who_is_died(t_the_philo *info);
void			ft_sleeping(t_the_philo *philo);
void			ft_eat(t_the_philo *philo);
void			ft_thinking(t_the_philo *info);
void			ft_teken_the_fork(sem_t *sem, t_the_philo *info);
int				check_death(t_philosophrs *philo);

#endif
