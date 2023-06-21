#include <philo.h>

bool sleeping(t_philo *phil, t_time *time)
{
//	usleep(500);
	if (check_if_alive(phil, time) == false)
	{
//		pthread_mutex_unlock(&phil->data_pool->mutex[SLEEP]);
		return (false);
	}
//	pthread_mutex_lock(&phil->data_pool->mutex[SLEEP]);
	if (print(&phil->data_pool->mutex[PRINT], phil, "is sleeping", time->start) == false)
	{
//		pthread_mutex_unlock(&phil->data_pool->mutex[SLEEP]);
		return (false);
	}
	if (time_sleep_and_validate(phil->data_pool->time_to_sleep, phil) == false)
	{
//		pthread_mutex_unlock(&phil->data_pool->mutex[SLEEP]);
		return (false);
	}
//	pthread_mutex_unlock(&phil->data_pool->mutex[SLEEP]);
	return (true);
}
