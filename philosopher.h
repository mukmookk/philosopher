#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	int				ms_eat;
	int				num_eat;
	int				finish;
	pthread_mutex_t	left;
	pthread_mutex_t	*right;
	pthread_t		thread_id;
	t_args			args;
}	t_philo;

typedef struct s_args
{
	int				total_num;
	int				d_time;
	int				e_time;
	int				s_time;
	int				e_num;
	int				stop;
	long long		start_t;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	dead;
	pthread_mutex_t	time_eat;
	pthread_mutex_t	finish;
}	t_args;

typedef struct s_p
{
	t_philo			*philo;
	t_args			args;
}	t_p;

long long	ft_atoi(const char *str);
int			ft_strlen(const char *str);
void		ft_putstr_fd(const char *str, int fd);
int			ft_exit(char *msg);

long int	actual_time(void);
void		ft_usleep(long int time_in_ms);
int			initialize(t_p *p);

#endif