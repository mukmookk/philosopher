/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmki <youngmki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 01:31:51 by youngmki          #+#    #+#             */
/*   Updated: 2022/03/17 11:58:39 by youngmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	check_death(t_philo *ph, int flag)
{
	pthread_mutex_lock(&ph->args.dead);
	if (flag == 1)
		ph->args.stop = 1;
	return (1);
}

long int	actual_time(void)
{
	long long		time;
	struct timeval	current_time;

	time = 0;
	if (gettimeofday(&current_time, NULL) == -1)
	{
		ft_exit("gettimeofday failed\n");
		return (-1);
	}
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

void	ft_usleep(long int time_in_ms)
{
	long int	start_time;

	start_time = actual_time();
	//if (start_time == -1)
	//	return (-1);
	while (actual_time() < start_time + time_in_ms)
		usleep(time_in_ms / 10);
}
