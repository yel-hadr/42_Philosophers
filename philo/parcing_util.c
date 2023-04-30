/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:43:22 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/04/30 21:41:03 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	memset (ptr, '\0', count * size);
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

int	chech_the_nbr(char *str)
{
	int	len;

	len = 0;
	while (*str == '0')
		str++;
	while (*(str++))
		len++;
	return (len);
}

int	check_is_valid(char *str)
{
	if (chech_the_nbr(str) > 12)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*(str++)))
			return (0);
	}
	return (1);
}
