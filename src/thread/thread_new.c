#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <philo.h>

static void	print(pthread_mutex_t *print, long id, char *message, int64_t start)
{
	pthread_mutex_lock(print);
//	printf("%lld ", time_difference_ms(time_of_day_ms(), start) * 1000);
	printf("%ld ", (long) time_difference_ms(time_of_day_ms(), start));
	printf("%ld", id);
	printf(" %s\n", message);
	pthread_mutex_unlock(print);
}

static bool	check_if_alive(pthread_mutex_t *time, int64_t time_since_last_meal, long time_to_die)
{
	pthread_mutex_lock(time);
	if (time_difference_ms(time_of_day_ms(), time_since_last_meal) >= (int64_t) time_to_die)
	{
		pthread_mutex_unlock(time);
		return (false);
	}
	pthread_mutex_unlock(time);
	return (true);
}

static void	*thread_function(void* arg)
{
	pthread_mutex_t	*stop;
	t_philo	        *phil;
	const int64_t	start = time_of_day_ms();
	int64_t			time_since_last_meal;
	long 			time_to_die;

	phil = (t_philo *)arg;
	ft_memcpy(&time_to_die, &phil->data_pool->time_to_die, sizeof(long));
	print(&phil->data_pool->mutex[PRINT], (long) phil->id, "starts", start);
	pthread_mutex_lock(&phil->data_pool->mutex[START]);
	pthread_mutex_unlock(&phil->data_pool->mutex[START]);
	stop = &phil->data_pool->mutex[STOP];
	time_since_last_meal = time_of_day_ms();
	while (1)
	{
		time_since_last_meal = time_of_day_ms();
		time_sleep_ms(1);
//		usleep(1);
		pthread_mutex_lock(stop);
		if (check_if_alive(&phil->data_pool->mutex[TIME], time_since_last_meal, time_to_die) == false)
		{
			print(&phil->data_pool->mutex[PRINT], (long)phil->id, "died", start);
			phil->data_pool->dead = true;
			pthread_mutex_unlock(stop);
			return (NULL);
		}
		if (phil->data_pool->dead == true)
		{
			pthread_mutex_unlock(stop);
			break ;
		}
		if (pthread_mutex_lock(&phil->left) == 0 && pthread_mutex_lock(&phil->right) == 0)
		{
			printf("%ld %ld has taken a fork\n", (long) time_difference_ms(time_of_day_ms(), start), (long)phil->id);
			printf("%ld %ld is eating\n", (long) time_difference_ms(time_of_day_ms(), start), (long)phil->id);
			time_sleep_ms(phil->data_pool->time_to_eat);
//			time_sleep_ms(1000);
			pthread_mutex_unlock(stop);
//			break ;
		}
//		print(&phil->data_pool->mutex[PRINT], (long)phil->id, "still inside while loop", start);
		pthread_mutex_unlock(stop);
	}
	print(&phil->data_pool->mutex[PRINT], (long)phil->id, "is still alive", start);
	return (NULL);
}

int thread_main_new(t_public *data_pool)
{
	pthread_t		*threads;
	t_philo			*philos;
	size_t 			i;
	t_public		pool_copy;

	ft_memcpy(&pool_copy, data_pool, sizeof(t_public));
	philos = malloc(pool_copy.number_of_philosophers * sizeof(t_philo));
	if (!philos)
		return (0);
	if (mutex_initialize(&data_pool->mutex, STOP + pool_copy.number_of_philosophers + 1) == false)
		  return (free(philos), 0);
	// need to protect these inits below
	pthread_mutex_init(&philos->left, NULL);
	pthread_mutex_init(&philos->right, NULL);
	data_pool->dead = false;
	threads = malloc(pool_copy.number_of_philosophers * sizeof(pthread_t));
	if (!threads)
		return (free(philos), pthread_mutex_destroy(data_pool->mutex), free(data_pool->mutex), 0);

	pthread_mutex_lock(&data_pool->mutex[START]);
	i = 0;
	while (i < (size_t) pool_copy.number_of_philosophers)
	{
		philos[i].id = i;
		philos[i].left = data_pool->mutex[STOP + i + 1];
		if ((STOP + i) == STOP)
			philos[i].right = data_pool->mutex[STOP + pool_copy.number_of_philosophers];
		else
			philos[i].right = data_pool->mutex[STOP + i];
		philos[i].data_pool = data_pool;
		if (pthread_create(&threads[i], NULL, thread_function, (void *)&philos[i]) != 0)
			return (pthread_mutex_unlock(&data_pool->mutex[START]), free(philos),
					pthread_mutex_destroy(data_pool->mutex), free(data_pool->mutex), 0);
// have to protect pthread_create
		i++;
	}
	printf("unlocking start mutex\n---------------------\n");
	pthread_mutex_unlock(&data_pool->mutex[START]);

	i = 0;

	while (i < (size_t) pool_copy.number_of_philosophers)
	{
		pthread_join(threads[i], NULL);
		i++;
	}

	free(threads);
	mutex_destroy(data_pool->mutex, STOP + pool_copy.number_of_philosophers + 1);
	free(data_pool->mutex);
	free(philos);
	return (0);
}
