#include <philo.h>

bool	stop_now(t_philo *phil)
{
	pthread_mutex_lock(&phil->data_pool->mutex[STOP]);
	if (phil->data_pool->stop == true)
	{
		pthread_mutex_unlock(&phil->data_pool->mutex[STOP]);
		return (true);
	}
	pthread_mutex_unlock(&phil->data_pool->mutex[STOP]);
	return (false);
}