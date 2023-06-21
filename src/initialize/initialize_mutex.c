#include "philo.h"

// check the protections of this function
bool	initialize_mutex(pthread_mutex_t **mutex, size_t number_of_philosophers)
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
