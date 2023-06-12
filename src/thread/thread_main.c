#include <philo.h>

static bool	mutex_initialize(pthread_mutex_t **mutex, size_t number_of_philosophers)
{
	size_t i;

	*mutex = malloc(number_of_philosophers * sizeof(pthread_mutex_t));
	if (!*mutex)
		return (false);
	i = 0;
	while (i < number_of_philosophers)
	{
		if (pthread_mutex_init(&(*mutex)[i], NULL) != 0)
			return (false);
		i++;
	}
	return (true);
}

bool	mutex_destroy(pthread_mutex_t *mutex, size_t number_of_philosophers)
{
	size_t i;

	i = 0;
	while (i < number_of_philosophers)
	{
		if (pthread_mutex_destroy(&mutex[i]) != 0)
			return (false);
		i++;
	}
	return (true);
}

static void	clean_up(pthread_t *thread, char **thread_result, pthread_mutex_t *mutex)
{
	if (thread)
		free(thread);
	if (thread_result)
		free(thread_result);
	if (mutex)
		free(mutex);
}

int thread_main(t_public *data_pool)
{
    char			**thread_result;
    pthread_t 		*thread;
	t_philo			phil;

    thread_result = NULL;
	if (initialize(data_pool, &phil, &thread_result, &thread) == false)
        return (0);
	if (mutex_initialize(&data_pool->mutex, data_pool->number_of_philosophers) == false)
		return (clean_up(thread, thread_result, NULL), 0);
	if (pthread_mutex_init(&data_pool->start_mutex, NULL) != 0)
		return (clean_up(thread, thread_result, data_pool->mutex), 0);
	// have to free start_mutex later
//	philos_create();
	thread_create(data_pool, &phil, thread);
	if (thread_join(data_pool->number_of_philosophers, thread, thread_result) == false)
		return (clean_up(thread, thread_result, data_pool->mutex), 0);
    thread_print_result(data_pool->number_of_philosophers, thread_result);
	if (mutex_destroy(data_pool->mutex, data_pool->number_of_philosophers) == false)
		return (clean_up(thread, thread_result, data_pool->mutex), 0);
	clean_up(thread, thread_result, data_pool->mutex);
    free(phil.id);
	return (0);
}
