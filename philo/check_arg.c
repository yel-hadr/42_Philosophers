/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 05:01:42 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/16 02:13:48 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	memset(ptr, '\0',count * size);
	return (ptr);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	s;
	int	i;
	int	r;

	s = 1;
	r = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			s *= -1;
	while (ft_isdigit(str[i]))
	{
		r = (r * 10) + (str[i++] - '0');
	}
	return (r * s);
}

int	check_is_valid(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*(str++)))
			return (0);
	}
	return (1);
}

void	check_arg(int ac , char **av, t_philosophrs *gen)
{
	int *ptr;
	int i;

	i = ac;
	ptr = ft_calloc(sizeof(int), ac - 1);
	if (!ptr)
		exit(1);
	while (ac-- > 1)
	{
		if (!check_is_valid(av[ac]))
		{
			printf("Oh, Errer wrong input !!\n");
			exit(1);
		}
		ptr[ac - 1] = ft_atoi(av[ac]);
	}
	gen->number_of_philosophers = ptr[0];
	if (gen->number_of_philosophers < 1)
	{
		printf ("you need more then one philosopher o start the programme !!");
		exit (1);
	}
	gen->time_to_die = ptr[1];
	gen->time_to_eat = ptr[2];
	gen->time_to_sleep = ptr[3];
	if (i == 6)
		gen->number_of_to_eat = ptr[4];
	free(ptr);
}