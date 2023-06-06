#include <philo.h>

static bool	initialize_thread(pthread_t **thread, size_t number_of_philosophers)
{
    *thread = malloc(number_of_philosophers * sizeof(pthread_t));
    if (!*thread)
        return (false);
    return (true);
}

static bool	initialize_arg(size_t **arg, size_t number_of_philosophers)
{
    *arg = malloc(number_of_philosophers * sizeof(size_t));
    if (!*arg)
        return (false);
    return (true);
}

static void	set_arg(size_t number_of_philosophers, size_t *arg)
{
    size_t i;

    i = 0;
    while (i < number_of_philosophers)
    {
        arg[i] = i + 1;
        i++;
    }
}

static bool	initialize_thread_result(size_t number_of_philosophers, char ***thread_result)
{
    *thread_result = malloc(number_of_philosophers * sizeof(char *));
    // maybe I have to free more stuff here, check previous allocated memory
    if (!*thread_result)
        return (false);
    return (true);
}

bool initialize(t_philo *phil, char ***thread_result, pthread_t **thread, size_t *arg)
{
    if (initialize_thread(thread, phil->number_of_philosophers) == false)
        return (false);
    if (initialize_arg(&arg, phil->number_of_philosophers) == false)
        return (free(*thread), false);
    set_arg(phil->number_of_philosophers, arg);
    phil->arg = arg;
    phil->i = 0;
	phil->data_pool = NULL;

	// data pool
//	phil->data_pool->stop = false;
	//

	//	maybe I have to free more stuff here, check previous allocated memory
    if (initialize_thread_result(phil->number_of_philosophers, thread_result) == false)
        return (free(*thread), free(arg), false);
    return (true);
}
