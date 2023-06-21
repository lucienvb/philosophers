#include <philo.h>

bool	check_if_alive(t_philo *phil, t_time *time)
{
	long	number_of_philosophers;

	pthread_mutex_lock(&phil->data_pool->mutex[TIME]);
	if (time_difference_ms(time_of_day_ms(), time->time_since_last_meal) >= (int64_t) time->time_to_die)
	{
		if (phil->data_pool->stop == true)
		{
			pthread_mutex_unlock(&phil->data_pool->mutex[TIME]);
			return (false);
		}
		print(&phil->data_pool->mutex[PRINT], phil, "died", time->start);
		phil->data_pool->stop = true;
		pthread_mutex_unlock(&phil->data_pool->mutex[TIME]);
		return (false);
	}
	pthread_mutex_unlock(&phil->data_pool->mutex[TIME]);
	pthread_mutex_lock(&phil->data_pool->mutex[MEALS]);
	ft_memcpy(&number_of_philosophers, &phil->data_pool->number_of_philosophers, sizeof(long));
	if (phil->data_pool->reached_meal_count == number_of_philosophers)
	{
		pthread_mutex_unlock(&phil->data_pool->mutex[MEALS]);
		phil->data_pool->stop = true;
	}
	pthread_mutex_unlock(&phil->data_pool->mutex[MEALS]);
	return (true);
}
