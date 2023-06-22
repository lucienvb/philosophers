/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   thread_main.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/22 14:37:24 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/06/22 14:37:25 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static bool	initialize_thread_main(t_philo **philos, t_public *data_pool,
							long number_of_philosophers, pthread_t **threads)
{
	*philos = malloc(number_of_philosophers * sizeof(t_philo));
	if (!*philos)
		return (false);
	if (initialize_mutex(&data_pool->mutex, STOP + number_of_philosophers + 1)
		== false)
		return (free(*philos), false);
	if (initialize_threads(threads, number_of_philosophers) == false)
		return (free(*philos), pthread_mutex_destroy(data_pool->mutex),
			free(data_pool->mutex), false);
	return (true);
}

static void	clean_up_thread_main(t_philo *philos, t_public *data_pool,
								long number_of_philosophers, pthread_t *threads)
{
	free(threads);
	mutex_destroy(data_pool->mutex, STOP + number_of_philosophers + 1);
	free(data_pool->mutex);
	free(philos);
}

static bool	thread_create(t_philo *philos, t_public *data_pool,
							long number_of_philosophers, pthread_t *threads)
{
	size_t	i;

	i = 0;
	pthread_mutex_lock(&data_pool->mutex[START]);
	while (i < (size_t) number_of_philosophers)
	{
		initialize_philos(&(philos[i]), i, data_pool, number_of_philosophers);
		if (pthread_create(&threads[i], NULL, thread_routine,
				(void *)&philos[i]) != 0)
			return (pthread_mutex_unlock(&data_pool->mutex[START]),
				free(philos), pthread_mutex_destroy(data_pool->mutex),
				free(data_pool->mutex), false);
		i++;
	}
	data_pool->start = time_of_day_ms();
	pthread_mutex_unlock(&data_pool->mutex[START]);
	return (true);
}

int	thread_main(t_public *data_pool, long number_of_philosophers)
{
	pthread_t	*threads;
	t_philo		*philos;
	size_t		i;

	threads = NULL;
	if (initialize_thread_main(&philos, data_pool, number_of_philosophers,
			&threads) == false)
		return (0);
	if (thread_create(philos, data_pool, number_of_philosophers, threads)
		== false)
		return (0);
	i = 0;
	while (i < (size_t) number_of_philosophers)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	clean_up_thread_main(philos, data_pool, number_of_philosophers, threads);
	return (0);
}
