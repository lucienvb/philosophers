#include <philo.h>

void	thread_create(t_philo *philos, pthread_t *thread, long number_of_philosophers)
{
	size_t	i;

	pthread_mutex_lock(&philos->data_pool->start_mutex);
	i = 0;
	while (i < (size_t) number_of_philosophers)
    {
		if (pthread_create(&thread[i], NULL, thread_routine, (void *) &philos[i]) != 0)
		{
			free(&philos[i]);
			return ;
		}
		i++;
    }
	pthread_mutex_unlock(&philos->data_pool->start_mutex);
}
// if a following thread fails, the program has to stop
