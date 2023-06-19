#include <philo.h>

bool sleeping(t_philo *phil, t_time *time)
{
	print(&phil->data_pool->mutex[PRINT], (long)phil->id, "is sleeping", time->start);
	if (time_sleep_and_validate(phil->data_pool->time_to_sleep, phil) == false)
		return (false);
	return (true);
}
