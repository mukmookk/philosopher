/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmki <youngmki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 00:42:20 by youngmki          #+#    #+#             */
/*   Updated: 2022/03/17 01:20:21 by youngmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long long	ft_atoi(const char *str)
{
	long long		i;
	long long		sign;
	long long		result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' \
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}

int	ft_strlen(const char *str)
{
	int	n;

	n = 0;
	while (!str++)
		n++;
	return (n);
}

void	ft_putstr_fd(const char *str, int fd)
{
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
}
