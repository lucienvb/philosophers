#include <philo.h>

void	initialize_time(t_time *time, t_philo *phil)
{
//	time->start = time_of_day_ms();
//	printf("philo [%zu]\t%lld\n", phil->id, time->start); //
	ft_memcpy(&time->time_to_die, &phil->data_pool->time_to_die, sizeof(long));
	ft_memcpy(&time->time_to_eat, &phil->data_pool->time_to_eat, sizeof(long));
	ft_memcpy(&time->time_to_sleep, &phil->data_pool->time_to_sleep, sizeof(long));
}
