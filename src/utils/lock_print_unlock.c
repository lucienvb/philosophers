#include <philo.h>

// try to get rid of the time_sleep_ms(1)
void	print(pthread_mutex_t *print, t_philo *phil, char *message, int64_t start)
{
	time_sleep_ms(1); // would be better to get rid of this one
	pthread_mutex_lock(print);
	if (stop_now(phil) == true)
	{
		pthread_mutex_unlock(print);
		return ;
	}
	printf("%ld ", (long) time_difference_ms(time_of_day_ms(), start));
	printf("%ld", phil->id);
	printf(" %s\n", message);
	pthread_mutex_unlock(print);
}

// need to print at time = 0 [ALL PHILOS]
