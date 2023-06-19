#include <philo.h>

void	print(pthread_mutex_t *print, long id, char *message, int64_t start)
{
	pthread_mutex_lock(print);
//	printf("%lld ", time_difference_ms(time_of_day_ms(), start) * 1000);
	printf("%ld ", (long) time_difference_ms(time_of_day_ms(), start));
	printf("%ld", id);
	printf(" %s\n", message);
	pthread_mutex_unlock(print);
}
