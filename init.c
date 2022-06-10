/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmki <youngmki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 01:29:21 by youngmki          #+#    #+#             */
/*   Updated: 2022/03/17 11:59:20 by youngmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	init_mutex(t_p *p)
{
	pthread_mutex_init(&p->args.write_mutex, NULL);
	pthread_mutex_init(&p->args.dead, NULL);
	pthread_mutex_init(&p->args.time_eat, NULL);
	pthread_mutex_init(&p->args.finish, NULL);
}

int	initialize(t_p *p)
{
	int	i;
	int	error;

	i = 0;
	p->args.start_t = actual_time();
	p->args.stop  = 0;
	p->args.dead = 0;
	init_mutex(p);
	while (i < p->args.total_num)
	{
		p->philo[i].id = i + 1;
		p->philo[i].ms_eat = p->args.start_t;
		p->philo[i].num_eat = 0;
		p->philo[i].finish = 0;
		p->philo[i].right = NULL;
		//error = pthread_mutex_init(&p->philo[i].right, NULL);
		p->philo[i].right = NULL;
		error = pthread_mutex_init(&p->philo[i].left, NULL);
		if (error != 0)
			return (-1);
		// TEST REQUIRED
		if (i == p->args.total_num - 1)
			p->philo[i].right = &p->philo[0].left;
		else
			p->philo[i].right = &p->philo[i+1].left;
		i++;
	}
	return (1);
}
