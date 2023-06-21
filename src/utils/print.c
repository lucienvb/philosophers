#include <philo.h>

// try to get rid of the time_sleep_ms(1)
bool	print(pthread_mutex_t *print, t_philo *phil, char *message, int64_t start)
{
	pthread_mutex_lock(print);
	if (stop_now(phil) == true)
	{
		pthread_mutex_unlock(print);
		return (false);
	}
	printf("%ld ", (long) time_difference_ms(time_of_day_ms(), start));
	printf("%ld", phil->id);
	printf(" %s\n", message);
	pthread_mutex_unlock(print);
    return (true);
}

// need to print at time = 0 [ALL PHILOS]

