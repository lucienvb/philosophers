//#include "philo.h"
#include "../../include/philo.h"

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

static bool	mutex_destroy(pthread_mutex_t *mutex, size_t number_of_philosophers)
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


int thread_main(t_philo *phil)
{
    char			**thread_result;
    pthread_t 		*thread;
    size_t			*arg;
	pthread_mutex_t	*mutex;

    thread_result = NULL;
    arg = NULL;
	initialize(phil, &thread_result, &thread, arg);
	if (mutex_initialize(&mutex, phil->number_of_philosophers) == false)
		return (0);
	thread_create(phil, thread, &mutex);
   	// maybe free stuff when pthread_join fails (free everything that's previously malloc)
	if (thread_join(phil->number_of_philosophers, thread, thread_result) == false)
		return (0);
    thread_print_result(phil->number_of_philosophers, thread_result);
//	pthread_mutex_destroy(&mutex);
	if (mutex_destroy(mutex, phil->number_of_philosophers) == false)
		return (0);
	return (0);
}
