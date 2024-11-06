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

t_data	*inits(char **av)
{
	t_data			*t;
	long long		start;
	int				i;

	t = malloc(sizeof(t_data));
	if (!t)
		clean_up_data(NULL, EXIT_FAILURE);
	init_mutex(&t->mutex);
	t->philo_ct = atoi(av[1]);
    t->p = calloc(t->philo_ct, sizeof(t_philo));
	if (!t->p)
		clean_up_data(t, EXIT_FAILURE);
	i = 0;
	while (i < t->philo_ct)
	{
		t->p[i].id = i + 1;
		t->p[i].t = t;
		i++;
	}
	t->start = get_time();
	return (t);
}
