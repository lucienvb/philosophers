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
