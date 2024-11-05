#include "data.h" 

void	init_mutex(pthread_mutex_t *mutex)
{
	int	mutex_check;

	if ((mutex_check = pthread_mutex_init(mutex, NULL)) != 0)
	{
		printf("pthread_mutex_init: error\n");
		exit(EXIT_FAILURE);
	}
}

t_data	*inits(void)
{
	t_data *t;
	long long		start;

	t = malloc(sizeof(t_data));
	if (!t)
		clean_up_data(NULL, EXIT_FAILURE);
	init_mutex(&t->mutex);
	t->start = get_time();
	return (t);
}
