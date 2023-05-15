//#include "philo.h"
#include "../include/philo.h"


static void	*thread_function(void *arg)
{
	int i;

	i = 1;
	while (i <= 5)
	{
		printf("Thread function is running. Argument passed = %d, iteration = %d\n", *(int *)arg, i);
		usleep(500000);
		i++;
	}
	char *message = "Thread function is finished\n";
	return message;
}

int thread_main(size_t number_of_philosophers)
{
	pthread_t	*thread;
	int			*arg;
	size_t		i;
	char		*thread1_result;
	char		*thread2_result;
	char		*thread3_result;
	char		*thread4_result;
	char		*thread5_result;

	thread = malloc(number_of_philosophers * sizeof(pthread_t));
	if (!thread)
		return (0);
	arg = malloc(number_of_philosophers * sizeof(int));
	if (!arg)
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
		pthread_create(&thread[i], NULL, thread_function, &arg[i]);
		i++;
	}
	pthread_join(thread[0], (void **)&thread1_result);
	pthread_join(thread[1], (void **)&thread2_result);
	pthread_join(thread[2], (void **)&thread3_result);
	pthread_join(thread[3], (void **)&thread4_result);
	pthread_join(thread[4], (void **)&thread5_result);

	printf("result thread 1: %s\n", thread1_result);
	printf("result thread 2: %s\n", thread2_result);
	printf("result thread 3: %s\n", thread3_result);
	printf("result thread 4: %s\n", thread4_result);
	printf("result thread 5: %s\n", thread5_result);
	return 0;
}
