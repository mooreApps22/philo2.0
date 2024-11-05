#include "data.h"

void	clean_up_data(t_data *t, int status)
{
	if (t)
	{
		pthread_mutex_destroy(&t->mutex);
		free(t);
	}
	exit(status);
}
