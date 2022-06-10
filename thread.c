/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmki <youngmki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 10:40:29 by youngmki          #+#    #+#             */
/*   Updated: 2022/03/17 12:01:12 by youngmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*thread(void *p)
{
	t_philo			*philo;
	
	philo = (t_philo *)p;
	if (philo->id % 2 == 0)
		ft_usleep(philo->args.e_time / 10);
	
}

int threading(t_p *p)
{
	int	i;

	i = 0;
	while (i < p->args.total_num)
	{
		// 함수에 던지는 매개변수는 void* 형태이기 때문에 이후에, 함수 내에서 타입 캐스팅이 필요
		if (pthread_create(p->philo[i].thread_id, NULL, thread, &p->philo[i]))
			return (ft_exit("pthread_create error\n"));
		i++;
	}
}