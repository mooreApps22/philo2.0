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

void	init_philo(t_data *t)
{
	int	i;

    t->p = calloc(t->philo_ct, sizeof(t_philo));
	if (!t->p)
		clean_up_data(t, EXIT_FAILURE);
	i = 0;
	while (i < t->philo_ct)
	{
		t->p[i].id = i + 1;
		t->p[i].t = t;
		t->p[i].right = i;
		if (i == 0)
			t->p[i].left = t->philo_ct - 1;
		else
			t->p[i].left = i - 1;
		i++;
	}
}

t_data	*inits(char **av)
{
	t_data			*t;
	long long		start;

	t = malloc(sizeof(t_data));
	if (!t)
		clean_up_data(NULL, EXIT_FAILURE);
	init_mutex(&t->mutex_output);
	t->philo_ct = atoi(av[1]);
	t->eat_time = atoi(av[2]);
	t->sleep_time = atoi(av[3]);
	t->forks = calloc(t->philo_ct, (sizeof(pthread_mutex_t)));
	init_philo(t);
	t->start = get_time();
	return (t);
}
