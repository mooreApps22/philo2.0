#include "data.h"

void		output_time_stamp(t_philo *p, int elasped, char *msg)
{
	pthread_mutex_lock(&p->t->mutex);
//	mssleep(elasped);
	printf("%s %d  %lld\n", msg, p->id, elapsed_time(p->t->start));
	pthread_mutex_unlock(&p->t->mutex);
}
