#include <philo.h>

bool diner(t_philo *phil, t_time *time)
{
	if (pthread_mutex_lock(phil->left) == 0 && pthread_mutex_lock(phil->right) == 0)
	{
		if (check_if_alive(phil, time->time_since_last_meal, time->time_to_die) == false)
		{
			pthread_mutex_unlock(phil->left);
			pthread_mutex_unlock(phil->right);
			return (false);
		}
		if (pthread_mutex_lock(&phil->data_pool->mutex[MEAL]) == 0)
		{
			phil->meal_count++;
			if (phil->meal_count == phil->number_of_times_each_philosopher_must_eat)
				phil->data_pool->reached_meal_count++;
			pthread_mutex_unlock(&phil->data_pool->mutex[MEAL]);
		}
		print(&phil->data_pool->mutex[PRINT], (long)phil->id, "has taken a fork", time->start);
		print(&phil->data_pool->mutex[PRINT], (long)phil->id, "is eating", time->start);
		if (time_sleep_and_validate(phil->data_pool->time_to_eat, phil) == false)
			return (false);
		pthread_mutex_unlock(phil->left);
		pthread_mutex_unlock(phil->right);
	}
	return (true);
}
