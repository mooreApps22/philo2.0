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
	pthread_mutex_t	mutex;
	long long		start;
	t_philo			*p;
	int				philo_ct;
} t_data;

typedef struct	s_philo
{
	pthread_t		tid;
	int				id;
	t_data			*t;
} t_philo_tid;

t_data		*inits(char **av);
long long	get_time(void);
long long	elapsed_time(long long then);
void		mssleep(int ms);
void		output_time_stamp(t_philo *p, int elasped, char *msg);
void		init_mutex(pthread_mutex_t *mutex);
void		clean_up_data(t_data *t, int status);

#endif
