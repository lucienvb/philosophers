#include <philo.h>

static bool	initialize_thread(pthread_t **thread, size_t number_of_philosophers)
{
    *thread = malloc(number_of_philosophers * sizeof(pthread_t));
    if (!*thread)
        return (false);
    return (true);
}

static size_t	*initialize_id(size_t number_of_philosophers)
{
    return (malloc(number_of_philosophers * sizeof(size_t)));
}

static void	set_id(size_t number_of_philosophers, size_t *id)
{
    size_t i;

    i = 0;
    while (i < number_of_philosophers)
    {
        id[i] = i + 1;
        i++;
    }
}

static bool	initialize_thread_result(size_t number_of_philosophers, char ***thread_result)
{
    *thread_result = malloc(number_of_philosophers * sizeof(char *));
    if (!*thread_result)
        return (false);
    return (true);
}

bool initialize(t_public *data_pool, t_philo *phil, char ***thread_result, pthread_t **thread)
{
    if (initialize_thread(thread, data_pool->number_of_philosophers) == false)
	{
        return (false);
	}
	phil->id = initialize_id(data_pool->number_of_philosophers);
    if (phil->id == NULL)
        return (free(*thread), false);
    set_id(data_pool->number_of_philosophers, phil->id);
    phil->i = 0;
	data_pool->test = 0;
    if (initialize_thread_result(data_pool->number_of_philosophers, thread_result) == false)
		return (free(*thread), free(phil->id), false);
    return (true);
}
