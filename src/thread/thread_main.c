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

static t_philo	*philos_create(t_philo *phil, t_public *data_pool)
{
	size_t	i;
	t_philo	*philos;

	philos = malloc(data_pool->number_of_philosophers * sizeof(t_philo));
	if (!philos)
		return (NULL);
	i = 0;
	while (i < (size_t) data_pool->number_of_philosophers)
	{
        ft_memcpy(&philos[i], phil, sizeof(t_philo *));
		philos[i].data_pool = data_pool;
		philos[i].i = i;
		i++;
	}
	return (philos);
}

int thread_main(t_public *data_pool)
{
    char			**thread_result;
    pthread_t 		*thread;
	t_philo			phil;
	t_philo			*philos;

    thread_result = NULL;
	if (initialize(data_pool, &phil, &thread_result, &thread) == false)
        return (0);
	if (mutex_initialize(&data_pool->mutex, data_pool->number_of_philosophers) == false)
		return (clean_up(thread, thread_result, NULL), 0);
	if (pthread_mutex_init(&data_pool->start_mutex, NULL) != 0)
		return (clean_up(thread, thread_result, data_pool->mutex), 0);
	philos = philos_create(&phil, data_pool);
	if (!philos)
		return (clean_up(thread, thread_result, data_pool->mutex), 0);
	thread_create(philos, thread, data_pool->number_of_philosophers);
	if (thread_join(data_pool->number_of_philosophers, thread, thread_result) == false)
		return (clean_up(thread, thread_result, data_pool->mutex), 0);
    thread_print_result(data_pool->number_of_philosophers, thread_result);
	if (mutex_destroy(data_pool->mutex, data_pool->number_of_philosophers) == false)
		return (clean_up(thread, thread_result, data_pool->mutex), 0);
	if (pthread_mutex_destroy(&data_pool->start_mutex) != 0)
		return (clean_up(thread, thread_result, data_pool->mutex), 0);
	clean_up(thread, thread_result, data_pool->mutex);
    free(phil.id);
	free(philos);
	return (0);
}
