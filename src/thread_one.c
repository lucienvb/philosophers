//#include "philo.h"
#include "../include/philo.h"


static void	*thread_function(void *arg)
{
	int i;

	i = 1;
	while (i <= 3)
	{
		printf("Thread function is running. Argument passed = %d, iteration = %d\n", *(int *)arg, i);
		usleep(250000);
		i++;
	}
	char *message = "Thread function is finished\n";
	return message;
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
	*arg = malloc(number_of_threads * sizeof(int));
	if (!*arg)
		return (false);
	return (true);
}

int thread_main(size_t number_of_philosophers)
{
	pthread_t	*thread;
	size_t	 	*arg;
	size_t		i;
	char		**thread_result;

	if (initialize_threads(&thread, number_of_philosophers) == false)
		return (0);
	if (initialize_args(&arg, number_of_philosophers) == false)
		return (free(thread), 0);
	i = 0;
	while (i < number_of_philosophers)
	{
		arg[i] = i + 1;
		i++;
	}
	i = 0;
	while (i < number_of_philosophers)
	{
		// maybe free stuff when pthread_create fails (free everything that's previously malloc)
		if (pthread_create(&thread[i], NULL, thread_function, (int **) &arg[i]) != 0)
			return (0);
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
