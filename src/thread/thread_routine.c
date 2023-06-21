#include <philo.h>

void	*thread_routine(void* arg)
{
	t_philo	        *phil;
	t_time          time;

	phil = (t_philo *)arg;
	pthread_mutex_lock(&phil->data_pool->mutex[START]);
	time.start = phil->data_pool->start;
	pthread_mutex_unlock(&phil->data_pool->mutex[START]);
	initialize_time(&time, phil); // perhaps after actual start of philos [2 lines down?]
	//printf("philo [%zu]\t%lld\n", phil->id, time_difference_ms(time_of_day_ms(), time.start));
	time.time_since_last_meal = time_of_day_ms();
	while (1)
	{
		if (diner(phil, &time) == false)
			break ;
		if (sleeping(phil, &time) == false)
			break ;
		if (print(&phil->data_pool->mutex[PRINT], phil, "is thinking", time.start) == false)
            break ;
	}
    return (NULL);
}
