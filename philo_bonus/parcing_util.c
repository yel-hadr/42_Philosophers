/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:24:39 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/30 20:05:29 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	memset(ptr, '\0', count * size);
	return (ptr);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long long int	ft_atoi(const char *str)
{
	long long int	r;
	int				s;
	int				i;

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
		if (r < INT_MIN || r > INT_MAX)
		{
			printf ("%sError: Number too big! Please enter a smaller \
value.%s\n", URED, NOC);
			exit(1);
		}
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
