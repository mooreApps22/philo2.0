#include "data.h"

void	eat(t_philo *p, pthread_mutex_t *right, pthread_mutex_t *left, int ms)
{
	pthread_mutex_lock(right);
	output_time_stamp(p,"has taken a fork", 0);	
	pthread_mutex_lock(left);
	output_time_stamp(p,"has taken a fork", 0);	
	output_time_stamp(p,"is eating", ms);	
	pthread_mutex_unlock(right);
	pthread_mutex_unlock(left);
}

void	*start_philo(void *vptr)
{
	t_philo	*p;
	t_data	*t;

	p = (t_philo *)vptr;
	t = p->t;
	if (p->id % 1)
		usleep(1500);
	while (1)
	{
		eat(p, &t->forks[p->right], &t->forks[p->left], t->eat_time);
		output_time_stamp(p,"is sleeping", t->sleep_time);	
		output_time_stamp(p,"is thinking", 0);	
	}
	return (NULL);
}
