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

void		output_time_stamp(t_data *t, int elasped, char *msg)
{
	pthread_mutex_lock(&t->mutex);
	mssleep(elasped);
	printf("%s %lld\n", msg, elapsed_time(t->start));
	pthread_mutex_unlock(&t->mutex);
}

int	main(void)
{
	t_data			*t;

	t = inits();
	output_time_stamp(t, 500, "hello");
	clean_up_data(t, EXIT_SUCCESS);
}
