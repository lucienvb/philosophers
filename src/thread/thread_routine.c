#include <philo.h>

void	*thread_routine(void* arg)
{
	t_philo	        *phil;
	t_time          time;
	bool            first_meal;

	phil = (t_philo *)arg;
	initialize_time(&time, phil); // perhaps after actual start of philos [2 lines down?]
	pthread_mutex_lock(&phil->data_pool->mutex[START]);
	time.start = phil->data_pool->start;
	pthread_mutex_unlock(&phil->data_pool->mutex[START]);
	//printf("philo [%zu]\t%lld\n", phil->id, time_difference_ms(time_of_day_ms(), time.start));
	first_meal = true;
	while (1)
	{
		if (first_meal == true)
		{
			time.time_since_last_meal = time_of_day_ms();
			first_meal = false;
		}
		if (diner(phil, &time) == false)
			break ;
		time.time_since_last_meal = time_of_day_ms();
		if (sleeping(phil, &time) == false)
			break ;
		if (print(&phil->data_pool->mutex[PRINT], phil, "is thinking", time.start) == false)
            break ;
	}
//    printf("%i\n", phil->data_pool->stop);
    return (NULL);
}
