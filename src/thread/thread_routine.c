#include <philo.h>

void	*thread_routine(void* arg)
{
//	pthread_mutex_t	*stop;
	t_philo	        *phil;
	t_time          time;
	bool            first_meal;

	phil = (t_philo *)arg;
	initialize_time(&time, phil); // perhaps after actual start of philos [2 lines down?]
	pthread_mutex_lock(&phil->data_pool->mutex[START]);
	pthread_mutex_unlock(&phil->data_pool->mutex[START]);
	//printf("philo [%zu]\t%lld\n", phil->id, time_difference_ms(time_of_day_ms(), time.start));
//	stop = &phil->data_pool->mutex[STOP];
	first_meal = true;
	while (1)
	{
		// check if it needs to stop
		if (first_meal == true)
		{
			time.time_since_last_meal = time_of_day_ms();
			first_meal = false;
		}
//		if (time_sleep_and_validate(phil->data_pool->time_to_eat, phil) == false)
//			break ;
		if (diner(phil, &time) == false)
			break ;
		time.time_since_last_meal = time_of_day_ms();
		if (sleeping(phil, &time) == false)
			break ;
		print(&phil->data_pool->mutex[PRINT], phil, "is thinking", time.start);
	}
//	if (phil->dead == true)
//	{
//		print(&phil->data_pool->mutex[PRINT], phil, "died", time.start);
//	}
	return (NULL);
}
