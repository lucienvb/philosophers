#include <philo.h>


void	*thread_routine(void *tmp)
{
    size_t *id;
    t_philo *phil;


	phil = (t_philo *) tmp;
	id = &phil->id[phil->i - 1];

	pthread_mutex_lock(&phil->data_pool->start_mutex);
	pthread_mutex_unlock(&phil->data_pool->start_mutex);
	printf("Philosopher %d starts: \n", *(int *) id);

	pthread_mutex_lock(&phil->data_pool->mutex[2]);
	phil->data_pool->test += 10;
	printf("Philosopher %d, test: %zu\n\n", *(int *) id, phil->data_pool->test);
    pthread_mutex_unlock(&phil->data_pool->mutex[2]);

//    pthread_mutex_lock(&phil->mutex[1]);
//    phil->test -= 2;
//    printf("Philosopher %d, test: %zu\n\n", *(int *) id, phil->test);
//    pthread_mutex_unlock(&phil->mutex[1]);
	printf("Philosopher %d ends: \n", *(int *) id);

    return (NULL);
}

// Need to fix that all the threads use the same mutexes and not copies of the same mutexes like now
/*void	*thread_routine(void *tmp)
{
    size_t	i;
    size_t	*id;
    t_philo	*phil;
	int32_t	previous_mutex_index;

    phil = (t_philo *) tmp;
	previous_mutex_index = (int32_t) phil->i - 1;
	if (previous_mutex_index == -1)
		previous_mutex_index = phil->number_of_philosophers - 1;
    id = &phil->id[phil->i];
//	printf("---------------------------------\n");
//	printf("Philosopher %d:\n", *(int *) id);
//	printf("current_mutex_index: %zu\n", phil->i);
//	printf("previous_mutex_index: %i\n", previous_mutex_index);
//	printf("number of philosophers: %zu\n", phil->number_of_philosophers);
//	printf("time to die: %zu\n", phil->time_to_die);
//	printf("time to eat: %zu\n", phil->time_to_eat);
//	printf("time to sleep: %zu\n", phil->time_to_sleep);
//	printf("---------------------------------\n\n");
	i = 0;
	if (phil->number_of_philosophers == 1)
	{
		usleep(phil->time_to_die * THOUSAND);
		return ("Philosopher has died\n");
	}
	while (i < (size_t) phil->time_to_die)
	{
		i++;
		if ((pthread_mutex_lock(&phil->mutex[phil->i]) == 0 && pthread_mutex_lock(&phil->mutex[previous_mutex_index])) == 0)
		{
			printf("Philosopher %d is eating\n", *(int *) id);
			usleep(phil->time_to_eat * THOUSAND);
			if (pthread_mutex_unlock(&phil->mutex[phil->i]) != 0)
				return ("unlocking mutex failed\n");
			if (pthread_mutex_unlock(&phil->mutex[previous_mutex_index]) != 0)
				return ("unlocking mutex failed\n");
			i = 0;
//			printf("Philosopher %d is sleeping\n", *(int *) id);
//			usleep(phil->time_to_sleep * THOUSAND);
//			printf("Philosopher %d is thinking\n", *(int *) id);
		}
		break ;
	}
    free(phil);
//	printf("Philosopher %d has died\n", *(int *) id);
    return ("Philosopher has died\n");
}*/
