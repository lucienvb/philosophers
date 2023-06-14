#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <philo.h>

pthread_mutex_t	start_mutex;

static void	start_sign(pthread_mutex_t *start_mutex, int num_threads, int *thread_counter)
{
	while (1)
	{
		pthread_mutex_lock(start_mutex);
		if (*thread_counter == num_threads)
		{
			pthread_mutex_unlock(start_mutex);
			break;
		}
		pthread_mutex_unlock(start_mutex);
		usleep(100);
	}
	pthread_mutex_lock(start_mutex);
	pthread_mutex_unlock(start_mutex);
}

static void* thread_function(void* arg)
{
	t_philo	*phil;

	phil = (t_philo *)arg;

	int num_threads = phil->data_pool->number_of_philosophers;

	printf("Thread %ld starting operation\n", (long)phil->i);
	pthread_mutex_lock(&start_mutex);
	phil->data_pool->thread_counter++;
	pthread_mutex_unlock(&start_mutex);

	while (1)
	{
		pthread_mutex_lock(&start_mutex);
		if (phil->data_pool->thread_counter == num_threads)
		{
			pthread_mutex_unlock(&start_mutex);
			break;
		}
		pthread_mutex_unlock(&start_mutex);
		usleep(100);
	}
	printf("Thread %ld finished operation\n", (long)phil->i);
	return (NULL);
}

int thread_main_new(t_public *data_pool)
{
	pthread_t		*threads;
	pthread_mutex_t	start_mutex;
	t_philo			phil;
	t_philo			*philos;

	philos = malloc(data_pool->number_of_philosophers * sizeof(t_philo));
	if (!philos)
		return (0);
	if (pthread_mutex_init(&start_mutex, NULL) != 0)
		return (free(philos), 0);
	threads = malloc(data_pool->number_of_philosophers * sizeof(pthread_t));
	if (!threads)
		return (free(philos), pthread_mutex_destroy(&start_mutex), 0);
	phil.i = 0;
	while (phil.i < (size_t) data_pool->number_of_philosophers)
	{
		ft_memcpy(&philos[phil.i], &phil, sizeof(phil));
		if (&philos[phil.i] == NULL)
			return (free(philos), free(threads), pthread_mutex_destroy(&start_mutex), 0);
		philos[phil.i].data_pool = data_pool;
//		philos[phil.i].data_pool->start_mutex = start_mutex;
		pthread_create(&threads[phil.i], NULL, thread_function, (void *)&philos[phil.i]);
		pthread_detach(threads[phil.i]);
		phil.i++;
	}
	start_sign(&start_mutex, data_pool->number_of_philosophers, &data_pool->thread_counter);
	phil.i = 0;
	while (phil.i < (size_t) data_pool->number_of_philosophers)
	{
		pthread_join(threads[phil.i], NULL);
		phil.i++;
	}
	free(threads);
	pthread_mutex_destroy(&start_mutex);
	return (0);
}
