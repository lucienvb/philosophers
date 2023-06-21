#include <philo.h>

int thread_main_new(t_public *data_pool, long number_of_philosophers)
{
	pthread_t		*threads;
	t_philo			*philos;
	size_t 			i;

	philos = malloc(number_of_philosophers * sizeof(t_philo));
	if (!philos)
		return (0);
	if (mutex_initialize(&data_pool->mutex, STOP + number_of_philosophers + 1) == false)
		return (free(philos), 0);
    data_pool->stop = false;
	threads = malloc(number_of_philosophers * sizeof(pthread_t));
	if (!threads)
		return (free(philos), pthread_mutex_destroy(data_pool->mutex), free(data_pool->mutex), 0);
	pthread_mutex_lock(&data_pool->mutex[START]);
	i = 0;
	while (i < (size_t) number_of_philosophers)
	{
		initialize_philos(&(philos[i]), i, data_pool, number_of_philosophers);
		if (pthread_create(&threads[i], NULL, thread_routine, (void *)&philos[i]) != 0)
			return (pthread_mutex_unlock(&data_pool->mutex[START]), free(philos),
					pthread_mutex_destroy(data_pool->mutex), free(data_pool->mutex), 0);
// have to protect pthread_create
		i++;
    }
	pthread_mutex_lock(&data_pool->mutex[TIME]);
	data_pool->start = time_of_day_ms();
	pthread_mutex_unlock(&data_pool->mutex[TIME]);
	pthread_mutex_unlock(&data_pool->mutex[START]);
	i = 0;
	while (i < (size_t) number_of_philosophers)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	free(threads);
	mutex_destroy(data_pool->mutex, STOP + number_of_philosophers + 1);
	free(data_pool->mutex);
	free(philos);
	return (0);
}
