#include "data.h"

void	clean_up_data(t_data *t, int status)
{
	if (t)
	{
		pthread_mutex_destroy(&t->mutex);
		if (t->p)
			free(t->p);
		free(t);
	}
	exit(status);
}
