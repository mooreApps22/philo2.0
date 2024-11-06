#include "data.h" 

/*
	ONLY EXTERNAL FUNCTIONS ALLOWED
	memset, printf, malloc, free, write,
	usleep, gettimeofday, pthread_create,
	pthread_detach, pthread_join, pthread_mutex_init,
	pthread_mutex_destroy, pthread_mutex_lock,
	pthread_mutex_unlock

 	cc *.c -fsanitize=thread
*/

void	*start_philo(void *vptr)
{
	t_philo	*p;
	t_data	*t;

	p = (t_philo *)vptr;
	t = p->t;
	mssleep(500);
	output_time_stamp(p, 0, "hello");	
	return (NULL);
}

void	validate_args(int ac)
{
	if (ac != 2)
	{
		clean_up_data(NULL, EXIT_FAILURE);
	}
}


int	main(int ac, char **av)
{
	t_data			*t;
	int				tid_check;
	int				i;

	validate_args(ac);
	t = inits(av);
	i = 0;
	while (i < t->philo_ct)
	{
		if (tid_check = pthread_create(&t->p[i].tid, NULL, &start_philo, &t->p[i]) != 0)	
		{
			printf("pthread_create\n");
			clean_up_data(t, EXIT_FAILURE);
		}
		i++;
	}
	i = 0;
	while (i < t->philo_ct)
		pthread_join(t->p[i++].tid, NULL);
	clean_up_data(t, EXIT_SUCCESS);
}
