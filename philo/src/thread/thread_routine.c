/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   thread_routine.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/22 14:37:31 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/06/22 14:37:33 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	initialize_routine(t_philo *phil, t_time *time)
{
	phil->id++;
	pthread_mutex_lock(&phil->data_pool->mutex[START]);
	time->start = phil->data_pool->start;
	pthread_mutex_unlock(&phil->data_pool->mutex[START]);
	initialize_time(time, phil);
	time->time_since_last_meal = time_of_day_ms();
}

static void	uneven_group(t_philo *phil, t_time time)
{
	while (1)
	{
		if (sleeping(phil, &time) == false)
			break ;
		if (print(&phil->data_pool->mutex[PRINT], phil, "is thinking",
				  time.start) == false)
			break ;
		if (diner(phil, &time, phil->right, phil->left) == false)
			break ;
	}
}

static void	even_group(t_philo *phil, t_time time)
{
	while (1)
	{
		if (diner(phil, &time, phil->right, phil->left) == false)
			break ;
		if (sleeping(phil, &time) == false)
			break ;
		if (print(&phil->data_pool->mutex[PRINT], phil, "is thinking",
				  time.start) == false)
			break ;
	}
}

void	*thread_routine(void *arg)
{
	t_philo	*phil;
	t_time	time;

	phil = (t_philo *)arg;
	initialize_routine(phil, &time);
	if (phil->id % 2 != 1)
		uneven_group(phil, time);
	else
		even_group(phil, time);
	return (NULL);
}
