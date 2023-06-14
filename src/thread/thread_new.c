#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <philo.h>

static void	print(pthread_mutex_t *print, long id, char *message)
{
	pthread_mutex_lock(print);
	printf("%ld", id);
	printf(" %s\n", message);
	pthread_mutex_unlock(print);
}

static void	*thread_function(void* arg)
{
	t_philo	        *phil;
	pthread_mutex_t	*stop;

	phil = (t_philo *)arg;
	print(&phil->data_pool->mutex[PRINT], (long) phil->id, "starts");
	pthread_mutex_lock(&phil->data_pool->mutex[START]);
	pthread_mutex_unlock(&phil->data_pool->mutex[START]);
	stop = &phil->data_pool->mutex[STOP];
	while (1)
	{
		usleep(1);
		pthread_mutex_lock(stop);
		if (phil->data_pool->dead == true)
		{
			pthread_mutex_unlock(stop);
			break ;
		}
		if (phil->id == 1)
		{
			phil->data_pool->dead = true;
			printf("%ld equals 1\n", (long)phil->id);
			pthread_mutex_unlock(stop);
			break ;
		}
		print(&phil->data_pool->mutex[1], (long)phil->id, "still inside while loop");
		pthread_mutex_unlock(stop);
	}
	print(&phil->data_pool->mutex[1], (long)phil->id, "stops");
//	free(phil);
	return (NULL);
}

int thread_main_new(t_public *data_pool)
{
	pthread_t		*threads;
	pthread_mutex_t	*start_mutex;
	size_t 			i;
	t_philo			*philos;

	philos = malloc(data_pool->number_of_philosophers * sizeof(t_philo));
	if (!philos)
		return (0);
	if (mutex_initialize(&data_pool->mutex, 3) == false)
		  return (free(philos), 0);
	data_pool->dead = false;
	start_mutex = &data_pool->mutex[0];
	threads = malloc(data_pool->number_of_philosophers * sizeof(pthread_t));
	if (!threads)
		return (free(philos), pthread_mutex_destroy(data_pool->mutex), free(data_pool->mutex), 0);

	pthread_mutex_lock(start_mutex);
	i = 0;
	while (i < (size_t) data_pool->number_of_philosophers)
	{
		philos[i].id = i;
		philos[i].data_pool = data_pool;
		pthread_create(&threads[i], NULL, thread_function, (void *)&philos[i]); // dit kan fout gaan moet afgevangen worden
		i++;
	}
	printf("unlocking start mutex\n");
	pthread_mutex_unlock(start_mutex);

	i = 0;

	while (i < (size_t) data_pool->number_of_philosophers)
	{
		pthread_join(threads[i], NULL);
		i++;
	}

	free(threads);
	mutex_destroy(data_pool->mutex, 3);
	free(data_pool->mutex);
	free(philos);
	return (0);
}
