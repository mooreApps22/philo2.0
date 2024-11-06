#include "data.h"

void		output_time_stamp(t_philo *p, char *msg, int ms)
{
	pthread_mutex_lock(&p->t->mutex_output);
	printf("%lld %d %s", elapsed_time(p->t->start), p->id, msg);
	printf(" right: %d, left: %d\n", p->right, p->left);
	if (ms > 0)
		mssleep(ms);
	pthread_mutex_unlock(&p->t->mutex_output);
}
