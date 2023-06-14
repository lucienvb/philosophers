#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <philo.h>

static void	start_sign_parent(pthread_mutex_t *start_mutex, int num_threads, int *thread_counter)
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

static void	start_sign_threads(t_philo *phil)
{
	pthread_mutex_t *start_mutex;

	start_mutex = &phil->data_pool->start_mutex;
	printf("Thread %ld starting operation\n", (long)phil->id);
	pthread_mutex_lock(start_mutex);
	phil->data_pool->thread_counter++;
	pthread_mutex_unlock(start_mutex);
	while (1)
	{
		pthread_mutex_lock(start_mutex);
		if (phil->data_pool->thread_counter == phil->data_pool->number_of_philosophers)
		{
			pthread_mutex_unlock(start_mutex);
			break;
		}
		pthread_mutex_unlock(start_mutex);
		usleep(100);
	}
}

static void	*thread_function(void* arg)
{
	t_philo	        *phil;

	phil = (t_philo *)arg;

	start_sign_threads(phil);
	printf("Thread %ld finished operation\n", (long)phil->id);
	return (NULL);
}

int thread_main_new(t_public *data_pool)
{
	pthread_t		*threads;
	pthread_mutex_t	*start_mutex;
	t_philo			phil;
	t_philo			*philos;

	philos = malloc(data_pool->number_of_philosophers * sizeof(t_philo));
	if (!philos)
		return (0);
	if (pthread_mutex_init(&data_pool->start_mutex, NULL) != 0)
		return (free(philos), 0);
    start_mutex = &data_pool->start_mutex;
	threads = malloc(data_pool->number_of_philosophers * sizeof(pthread_t));
	if (!threads)
		return (free(philos), pthread_mutex_destroy(start_mutex), 0);
	phil.id = 0;
	while (phil.id < (size_t) data_pool->number_of_philosophers)
	{
		ft_memcpy(&philos[phil.id], &phil, sizeof(phil));
		if (&philos[phil.id] == NULL)
			return (free(philos), free(threads), pthread_mutex_destroy(start_mutex), 0);
		philos[phil.id].data_pool = data_pool;
		pthread_create(&threads[phil.id], NULL, thread_function, (void *)&philos[phil.id]);
		pthread_detach(threads[phil.id]);
		phil.id++;
	}
	start_sign_parent(start_mutex, data_pool->number_of_philosophers, &data_pool->thread_counter);
	phil.id = 0;
	while (phil.id < (size_t) data_pool->number_of_philosophers)
	{
		pthread_join(threads[phil.id], NULL);
		phil.id++;
	}
	free(threads);
	pthread_mutex_destroy(start_mutex);
	return (0);
}
