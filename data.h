#ifndef DATA_H
#define DATA_H

#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct	s_data
{
	pthread_mutex_t	mutex;
	long long		start;
} t_data;

t_data		*inits(void);
long long	get_time(void);
long long	elapsed_time(long long then);
void		mssleep(int ms);
void		output_time_stamp(t_data *t, int elasped, char *msg);
void		init_mutex(pthread_mutex_t *mutex);
void		clean_up_data(t_data *t, int status);

#endif
