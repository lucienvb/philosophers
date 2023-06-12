#include <philo.h>

void	thread_create(t_public *data_pool, t_philo *phil, pthread_t *thread)
{
    t_philo		*thread_phil;

	pthread_mutex_lock(&data_pool->start_mutex);
	while (phil->i < (size_t) data_pool->number_of_philosophers)
    {
        thread_phil = malloc(sizeof(t_philo));
        if (!thread_phil)
            return ;
        ft_memcpy(thread_phil, phil, sizeof(t_philo));
		phil = thread_phil;
		phil->data_pool = data_pool;
        if (pthread_create(&thread[phil->i], NULL, thread_routine, (void *) phil) != 0)
		{
			free(thread_phil);
			return ;
		}
		phil->i++;
    }
	pthread_mutex_unlock(&data_pool->start_mutex);
}
