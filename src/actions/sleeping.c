#include <philo.h>

// this function let a thread sleep for a period of time_to_sleep
// before it does two checks:
// 1) if the thread is alive
// 2) if the thread needs to stop (because another thread has died)
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
	if (time_sleep_and_validate(time->time_to_sleep, phil) == false)
	{
//		pthread_mutex_unlock(&phil->data_pool->mutex[SLEEP]);
		return (false);
	}
//	pthread_mutex_unlock(&phil->data_pool->mutex[SLEEP]);
	return (true);
}
