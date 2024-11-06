#include "data.h"

long long	get_time(void)
{
	struct timeval	now;
	int				tv_check;

	if ((tv_check = gettimeofday(&now, NULL)) != 0)
	{
		printf("gettimeofday_now: error\n");
		return (-1);
	}
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}

long long	elapsed_time(long long then)
{
	long long		now;
	int				tv_check;

	now = get_time();
	return (now - then);
}

void	mssleep(int ms)
{
	long long	now;
	long long	start;
	long long	elapsed_ms;

	start = get_time();
	while (1)
	{
		usleep(500);
		now = get_time();
		elapsed_ms = now - start;
		if (elapsed_ms >= ms)
			break ;
	}
}

/*
void	mssleep(int ms)
{
	usleep(ms * 1000);
}
*/
