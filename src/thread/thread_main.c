#include <philo.h>

// check the protections of this function
bool	mutex_initialize(pthread_mutex_t **mutex, size_t number_of_philosophers)
{
	size_t i;

	*mutex = malloc(number_of_philosophers * sizeof(pthread_mutex_t));
	if (!*mutex)
		return (false);
	i = 0;
	while (i < number_of_philosophers)
	{
		if (pthread_mutex_init(&(*mutex)[i], NULL) != 0)
			return (free(*mutex), false);
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

//static void	clean_up(pthread_t *thread, char **thread_result, pthread_mutex_t *mutex)
//{
//	if (thread)
//		free(thread);
//	if (thread_result)
//		free(thread_result);
//	if (mutex)
//		free(mutex);
//}
//
//static t_philo	*philos_create(t_philo *phil, t_public *data_pool)
//{
//	size_t	i;
//	t_philo	*philos;
//
//	philos = malloc(data_pool->number_of_philosophers * sizeof(t_philo));
//	if (!philos)
//		return (NULL);
//	i = 0;
//	while (i < (size_t) data_pool->number_of_philosophers)
//	{
//        ft_memcpy(&philos[i], phil, sizeof(t_philo *));
//		philos[i].data_pool = data_pool;
//		philos[i].i = i;
//		i++;
//	}
//	return (philos);
//}
