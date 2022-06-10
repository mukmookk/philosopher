/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmki <youngmki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:23:09 by youngmki          #+#    #+#             */
/*   Updated: 2022/03/17 08:57:31 by youngmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_exit(char *msg)
{
	ft_putstr_fd("Error : ", 2);
	ft_putstr_fd(msg, 2);
	return (0);
}

static int	is_numeric(char **argv, int i, int j)
{
	long long	n;

	while (argv[j])
	{
		while (argv[j][i])
		{
			if (argv[j][i] < '0' || argv[j][i] > '9')
				return (0);
			i++;
		}
		n = ft_atoi(argv[j]);
		if (n < INT32_MIN || n > INT32_MAX)
			return (0);
		i = 0;
		j++;
	}
	return (1);
}

static int	parse_args(int argc, char **argv, t_p *p)
{
	if (argc != 5 && argc != 6)
		return (0);
	if (!is_numeric(argv, 0, 1))
		return (0);
	p->args.total_num = ft_atoi(argv[1]);
	p->args.d_time = ft_atoi(argv[2]);
	p->args.e_time = ft_atoi(argv[3]);
	p->args.s_time = ft_atoi(argv[4]);
	if (argc == 6 || !argv[5])
	{
		p->args.e_num = ft_atoi(argv[5]);
		if (p->args.e_num <= 0)
			return (0);
	}
	if (p->args.total_num <= 0 || p->args.d_time <= 0 || p->args.e_time <= 0 \
		|| p->args.s_time <= 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_p	p;

	if (!parse_args(argc, argv, &p))
		return (ft_exit("Invalid arguments\n"));
	p.philo = malloc(sizeof(t_philo) * p.args.total_num);
	if (!p.philo)
		return (ft_exit("Malloc returned NULL\n"));
	initialize(&p);
	//thread_start(&p);
}
