#include <philo.h>

// PRINT MUTEX
// this function prints a given message
// first it checks if another philosopher has died
// if so, it returns false
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
