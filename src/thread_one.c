//#include "philo.h"
#include "../include/philo.h"


static void	*thread_function(void *tmp)
{
	size_t	i;
    size_t  *arg;
    t_philo *phil;

    phil = (t_philo *) tmp;

    arg = &phil->arg[phil->i];
	i = 0;
	while (i < phil->time_to_die)
	{
		printf("Philosopher %d is thinking\n", *(int *) arg);
		usleep(250000);
		i++;
	}
    if (i == phil->time_to_die)
        return("philosopher has died\n");
	return ("philosopher is thinking\n");
}

static bool	initialize_threads(pthread_t **thread, size_t number_of_threads)
{
	*thread = malloc(number_of_threads * sizeof(pthread_t));
	if (!*thread)
		return (false);
	return (true);
}

static bool	initialize_args(size_t **arg, size_t number_of_threads)
{
	*arg = malloc(number_of_threads * sizeof(size_t));
	if (!*arg)
		return (false);
	return (true);
}

int thread_main(size_t number_of_philosophers, size_t time_to_die)
{
    char		**thread_result;
    pthread_t	*thread;
    t_philo		phil;
    size_t      *arg;
    size_t		i;
    t_philo     *thread_phil;

	if (initialize_threads(&thread, number_of_philosophers) == false)
		return (0);
	if (initialize_args(&arg, number_of_philosophers) == false)
		return (free(thread), 0);
	i = 0;
	while (i < number_of_philosophers)
	{
		arg[i] = i;
		i++;
	}
    i = 0;
	phil.arg = arg;
    phil.i = 0;
    phil.time_to_die = time_to_die;
	while (i < number_of_philosophers)
	{
        thread_phil = malloc(sizeof(t_philo));
        if (!thread_phil)
            return (0);

        memcpy(thread_phil, &phil, sizeof(t_philo));
		// maybe free stuff when pthread_create fails (free everything that's previously malloc)
		if (pthread_create(&thread[i], NULL, thread_function, (void *) thread_phil) != 0)
			return (0);
        phil.i++;
		i++;
	}
	thread_result = malloc(number_of_philosophers * sizeof(char *));
	// maybe I have to free more stuff here, check previous allocated memory
	if (!thread_result)
		return (free(thread), free(arg), 0);
	i = 0;
	while (i < number_of_philosophers)
	{
		// maybe free stuff when pthread_join fails (free everything that's previously malloc)
		if (pthread_join(thread[i], (void **) &thread_result[i]) != 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < number_of_philosophers)
	{
		printf("result thread %zu: %s\n", i + 1, thread_result[i]);
		i++;
	}
	return 0;
}
