#ifndef DATA_H
#define DATA_H

#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct	s_data	t_data;
typedef struct	s_philo	t_philo;

typedef struct	s_data
{
	int				eat_time;
	int				sleep_time;
	pthread_mutex_t	mutex_output;
	pthread_mutex_t	*forks;
	t_philo			*p;
	int				philo_ct;
	long long		start;
} t_data;

typedef struct	s_philo
{
	pthread_t		tid;
	int				id;
	t_data			*t;
	int				left;
	int				right;
} t_philo_tid;

t_data		*inits(char **av);
void		init_mutex(pthread_mutex_t *mutex);
void		init_philo(t_data *t);
long long	get_time(void);
long long	elapsed_time(long long then);
void		mssleep(int ms);
void		output_time_stamp(t_philo *p, char *msg, int ms);
void		clean_up_data(t_data *t, int status);
void		*start_philo(void *vptr);
void		eat(t_philo *p, pthread_mutex_t *right, pthread_mutex_t *left, int ms);

#endif
